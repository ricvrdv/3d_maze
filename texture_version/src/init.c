#include "../inc/game.h"

void    init_game(t_game *game)
{
    game->floor = 0x383838;
	game->ceiling = 0x87CEEB;
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        ft_error("Error: Failed to initialize MiniLibX.\n");
    game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "3D MAZE");
    if (!game->win_ptr)
    {
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
        ft_error("Error: Failed to create window for the game.\n");
    }
    game->img.img_ptr = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img.img_ptr)
        ft_error("Error: Failed to create image buffer\n");
    game->img.addr = mlx_get_data_addr(game->img.img_ptr,
        &game->img.bits_per_pixel, &game->img.line_length,
        &game->img.endian);
    game->img.width = SCREEN_WIDTH;
    game->img.height = SCREEN_HEIGHT;

    load_texture(game, &game->no_texture, "textures/north.xpm");
    load_texture(game, &game->so_texture, "textures/south.xpm");
    load_texture(game, &game->we_texture, "textures/west.xpm");
    load_texture(game, &game->ea_texture, "textures/east.xpm");

    init_player(game);
    init_map(game->map);
}

void    load_texture(t_game *game, t_img *texture, char *file_path)
{
    texture->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, file_path, &texture->width, &texture->height);
    if (!texture->img_ptr)
        ft_error("Error: Failed to load texture: %s\n");
    texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

void    draw_floor_ceiling(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < SCREEN_HEIGHT / 2)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            my_mlx_pixel_put(&game->img, x, y, game->ceiling);
            x++;
        }
        y++;
    }
    y = SCREEN_HEIGHT / 2;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            my_mlx_pixel_put(&game->img, x, y, game->floor);
            x++;
        }
        y++;
    }
}

void    init_player(t_game *game)
{
    game->key_w = false;
    game->key_s = false;
    game->key_a = false;
    game->key_d = false;
    game->key_left = false;
    game->key_right = false;
    
    game->posX = 22.0;
    game->posY = 12.0;
    game->dirX = -1.0;
    game->dirY = 0.0;
    game->planeX = 0.0;
    game->planeY = 0.66;
    game->move_speed = 0.02;
    game->rot_speed = 0.01;
}

void    init_map(int map[MAP_HEIGHT][MAP_WIDTH])
{
    int temp_map[MAP_HEIGHT][MAP_WIDTH] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
        {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
        {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    int y;
    int x;

    y = 0;
    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_WIDTH)
        {
            map[y][x] = temp_map[y][x];
            x++;
        }
        y++;
    }
}