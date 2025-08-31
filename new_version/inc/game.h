#ifndef GAME_H
# define GAME_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

typedef struct  s_img
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

typedef struct  s_game
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
    int     map[MAP_HEIGHT][MAP_WIDTH];
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    double  move_speed;
    double  rot_speed;
} t_game;

void    init_game(t_game *game);
void    init_player(t_game *game);
void    init_map(int map[MAP_HEIGHT][MAP_WIDTH]);

void    ft_error(char *message);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif