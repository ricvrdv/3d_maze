#ifndef GAME_H
# define GAME_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

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
    int     width;
    int     height;
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

int     main_loop(t_game *game);
void    raycast(t_game *game);
void    draw_vertical_line(t_game *game, int x, int start, int end, int color);

int     handle_keypress(int keycode, t_game *game);
void    move_player(t_game *game, int keycode);
void	rotate_player(t_game *game, double rot_speed);

void    ft_error(char *message);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
int     exit_game(t_game *game);

#endif