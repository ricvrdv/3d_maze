#include "../inc/game.h"

void    ft_error(char *message)
{
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int exit_game(t_game *game)
{
    if (game->img.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
    if (game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    if (game->mlx_ptr)
    {
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
    }
    exit(0);
}