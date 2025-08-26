#include "../inc/game.h"
/*
void    draw_textured_wall(t_game *game, int x, int start_y, int end_y, int tex_x, int texture_idx)
{
    t_texture   *tex;
    float       step;
    float       tex_pos;
    int         y;
    char        *screen_data;
    char        *tex_data;
    int         tex_bytes_per_pixel;
    int         tex_y;
    int         screen_pos;
    int         tex_pos_mem;

    tex = &game->textures[texture_idx];
    step = (float)tex->height / (end_y - start_y);
    tex_pos = 0;
    y = start_y;

    //screen_data = mlx_get_data_addr(game->screen.img, &game->bpp, &game->size_line, &game->endian);
    int tex_bpp, tex_size_line, tex_endian;
	tex_data = mlx_get_data_addr(tex->img, &tex_bpp, &tex_size_line, &tex_endian);
	//tex_data = mlx_get_data_addr(tex->img, &game->bpp, &game->size_line, &game->endian);

    //tex_bytes_per_pixel = game->bpp / 8;
    while (y < end_y)
    {
        tex_y = (int)tex_pos;
        if (tex_y >= tex->height)
            tex_y = tex->height - 1;
        screen_pos = y * game->size_line + x * tex_bytes_per_pixel;
        tex_pos_mem = tex_y * game->size_line + tex_x * tex_bytes_per_pixel;
        if (screen_pos + 3 < game->size_line * HEIGHT
            && tex_pos_mem + 3 < game->size_line * tex->height)
        {
            screen_data[screen_pos] = tex_data[tex_pos_mem];
			screen_data[screen_pos + 1] = tex_data[tex_pos_mem + 1];
			screen_data[screen_pos + 2] = tex_data[tex_pos_mem + 2];
        }
		tex_pos += step;
		y++;
    }
}
*/

void    draw_textured_wall(t_game *game, int x, int start_y, int end_y, int tex_x, int texture_idx)
{
    t_texture   *tex;
    float       step;
    float       tex_pos;
    int         y;
    char        *screen_data;
    char        *tex_data;
    int         tex_bytes_per_pixel;
    int         tex_y;
    int         screen_pos;
    int         tex_pos_mem;
	int			bytes_per_pixel;

    tex = &game->textures[texture_idx];
    step = (float)tex->height / (end_y - start_y);
    tex_pos = 0;
    y = start_y;

    //screen_data = mlx_get_data_addr(game->screen.img, &game->bpp, &game->size_line, &game->endian);
    int tex_bpp, tex_size_line, tex_endian;
	tex_data = mlx_get_data_addr(tex->img, &tex_bpp, &tex_size_line, &tex_endian);
	//tex_data = mlx_get_data_addr(tex->img, &game->bpp, &game->size_line, &game->endian);

    //tex_bytes_per_pixel = game->bpp / 8;
    while (y < end_y)
    {
        tex_y = (int)tex_pos;
        if (tex_y >= tex->height)
            tex_y = tex->height - 1;
        screen_pos = y * game->size_line + x * tex_bytes_per_pixel;
        tex_pos_mem = tex_y * game->size_line + tex_x * tex_bytes_per_pixel;
        if (screen_pos + 3 < game->size_line * HEIGHT
            && tex_pos_mem + 3 < game->size_line * tex->height)
        {
            screen_data[screen_pos] = tex_data[tex_pos_mem];
			screen_data[screen_pos + 1] = tex_data[tex_pos_mem + 1];
			screen_data[screen_pos + 2] = tex_data[tex_pos_mem + 2];
        }
		tex_pos += step;
		y++;
    }
}

void	mlx_draw_vertical_line(t_game *game, int x, int start_y, int end_y, int color)
{
    int	bytes_per_pixel;
	int	y;
	int	pos;
	
	bytes_per_pixel = game->bpp / 8;
    if (x < 0 || x >= WIDTH)
		return;
	if (start_y < 0)
		start_y = 0;

	if (end_y > HEIGHT)
		end_y = HEIGHT;
    
    y = start_y;
	while (y < end_y)
    {
        pos = y * game->size_line + x * bytes_per_pixel;
        game->data[pos] = color & 0xFF;
        game->data[pos + 1] = (color >> 8) & 0xFF;
        game->data[pos + 2] = (color >> 16) & 0xFF; 
		y++;
    }
}

void	fill_image(t_game *game, int color)
{
	int	bytes_per_pixel;
	int	total_size;
	int	i;
	
	bytes_per_pixel = game->bpp / 8;
    total_size = game->size_line * HEIGHT;
    
	i = 0;
    while (i < total_size)
    {
        game->data[i] = color & 0xFF;
        game->data[i + 1] = (color >> 8) & 0xFF;
        game->data[i + 2] = (color >> 16) & 0xFF;
		i += bytes_per_pixel;
    }
}