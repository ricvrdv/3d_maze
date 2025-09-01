#include "../inc/game.h"

int main()
{
    t_game  game;

    ft_memset(&game, 0, sizeof(t_game));
    init_game(&game);
    mlx_hook(game.win_ptr, 2, 1L<<0, key_press, &game); // &handle_keypress IS NOT needed because handle_keypress is already a memory address
    mlx_hook(game.win_ptr, 3, 1L<<1, key_release, &game.player);
    mlx_hook(game.win_ptr, 17, 0, exit_game, &game);
    mlx_loop_hook(game.mlx_ptr, main_loop, &game);
    mlx_loop(game.mlx_ptr);
    return (0);
}