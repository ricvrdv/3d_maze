#ifndef GAME_H
# define GAME_H

# define WIDTH 500
# define HEIGHT 200
# define TILE 64

# define NUM_TEXTURES 4

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

# define PI 3.14159265359

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "./minilibx/mlx.h"

typedef struct  s_texture
{
    void    *img;
    int     width;
    int     height;
} t_texture;

typedef struct  s_player
{
    float   x;
    float   y;
	float	angle;

    bool    key_up;
    bool    key_down;
    bool    key_left;
    bool    key_right;

	bool	left_rotate;
	bool	right_rotate;
} t_player;

typedef struct  s_game
{
    void    *mlx;
    void    *win;
    void    *img;

    char    *data;
    int     bpp;
    int     size_line;
    int     endian;
    t_player    player;

	char	**map;

    t_texture   textures[NUM_TEXTURES];
    t_texture   screen;
    int         floor_color;
    int         ceiling_color;
} t_game;

void	init_player(t_player *player);
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player);
void    clear_image(t_game *game);
void    load_textures(t_game *game);
void    draw_textured_wall(t_game *game, int x, int start_y, int end_y, int tex_x, int texture_idx);
void	mlx_draw_vertical_line(t_game *game, int x, int start_y, int end_y, int color);
void	fill_image(t_game *game, int color);

#endif