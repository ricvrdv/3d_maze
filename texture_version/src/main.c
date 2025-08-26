#include "../inc/game.h"

void    put_pixel(int x, int y, int color, t_game *game)
{
    int index;

    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;
        
    index = y * game->size_line + x * game->bpp / 8;
    game->data[index] = color & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;
}

void    draw_square(int x, int y, int size, int color, t_game *game)
{
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y, color, game);

    for (int i = 0; i < size; i++)
        put_pixel(x, y + i, color, game);

    for (int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, game);

    for (int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, game);
}

void    draw_map(t_game *game)
{
    char    **map;
    int     color;

    map = game->map;
    color = 0xFF0000;
    for (int y = 0; map[y]; y++)
        for (int x = 0; map[y][x]; x++)
            if (map[y][x] == '1')
                draw_square(x * TILE, y * TILE, TILE,color, game);

}

void    clear_image(t_game *game)
{
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            put_pixel(x, y, 0, game);
}

char    **get_map(void)
{
    char    **map = malloc(sizeof(char *) * 11);

    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100011101111101";
    map[3] = "100000101000101";
    map[4] = "100000100000101";
    map[5] = "100000110000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

void    init_game(t_game *game)
{
    init_player(&game->player);
    game->map = get_map();
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "TEST");
    
    game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->screen.width = WIDTH;
    game->screen.height = HEIGHT;
    game->data = mlx_get_data_addr(game->screen.img, &game->bpp, &game->size_line, &game->endian);
    load_textures(game);
    mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / TILE;
	y = py / TILE;

	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	draw_line(t_player *player, t_game *game, float ray_angle, int x)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	float	dist;
    float   perp_dist;
	float	wall_height;
    int     wall_top;
    int     wall_bottom;
    int     texture_num;
    float   wall_x;
    int     tex_x;

	cos_angle = cos(ray_angle);
	sin_angle = sin(ray_angle);
	ray_x = player->x;
	ray_y = player->y;

	while (!touch(ray_x, ray_y, game))
	{
		//put_pixel(ray_x, ray_y, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
	perp_dist = dist * cos(ray_angle - player->angle);
	wall_height = (int)(HEIGHT / perp_dist);
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
    if (fabs(cos_angle) > fabs(sin_angle))
    {
        if (cos_angle > 0)
            texture_num = 0;
        else
			texture_num = 1;
    }
	else
	{
		if (sin_angle > 0)
			texture_num = 2;
		else
			texture_num = 3;
	}

	if (fabs(cos_angle) > fabs(sin_angle))
		wall_x = ray_y - floor(ray_y / TILE) * TILE;
	else
		wall_x = ray_x - floor(ray_x / TILE) * TILE;
	tex_x = (int)(wall_x * game->textures[texture_num].width / TILE);
	mlx_draw_vertical_line(game, x, 0, (HEIGHT - wall_height) / 2, game->ceiling_color);
	wall_top = (HEIGHT - wall_height) / 2;
	wall_bottom = wall_top + wall_height;
	draw_textured_wall(game, x, wall_top, wall_bottom, tex_x, texture_num);
	mlx_draw_vertical_line(game, x, wall_bottom, HEIGHT, game->floor_color);
}

int draw_loop(t_game *game)
{
    t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

    player = &game->player;
    move_player(player);
	fill_image(game, 0x000000);
    //clear_image(game);
    //draw_square(player->x, player->y, 10, 0x00FF00, game);
    //draw_map(game);

	fraction = (PI / 3) / WIDTH;
	start_x = player->angle - (PI / 6);
	i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
    mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
    return (0);
}

int main()
{
    t_game  game;

    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
    
    mlx_loop_hook(game.mlx, draw_loop, &game);
    mlx_loop(game.mlx);

    return (0);
}