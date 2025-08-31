#include "../inc/game.h"

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        exit_game(game);
    }
    else if (keycode == KEY_W || keycode == KEY_S
        || keycode == KEY_A || keycode == KEY_D
        || keycode == KEY_LEFT || keycode == KEY_RIGHT)
        move_player(game, keycode);
    return (0);
}

void    move_player(t_game *game, int keycode)
{
    double  moveX;
	double  moveY;

    moveX = 0;
    moveY = 0;
	if (keycode == KEY_W)
	{
		moveX = game->dirX * game->move_speed;
		moveY = game->dirY * game->move_speed;
	}
	else if (keycode == KEY_S)
	{
		moveX = -game->dirX * game->move_speed;
		moveY = -game->dirY * game->move_speed;
	}
	else if (keycode == KEY_A)
	{
		moveX = -game->dirY * game->move_speed;
		moveY = game->dirX * game->move_speed;
	}
	else if (keycode == KEY_D)
	{
		moveX = game->dirY * game->move_speed;
		moveY = -game->dirX * game->move_speed;
	}
	else if (keycode == KEY_LEFT)
		rotate_player(game, game->rot_speed);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, -game->rot_speed);
	if (game->map[(int)(game->posY)][(int)(game->posX + moveX)] == 0)
		game->posX += moveX;
	if (game->map[(int)(game->posY + moveY)][(int)(game->posX)] == 0)
		game->posY += moveY;
}

void	rotate_player(t_game *game, double rot_speed)
{
	double  oldDirX;
    double  oldPlaneX;

    oldDirX = game->dirX;
	game->dirX = game->dirX * cos(rot_speed) - game->dirY * sin(rot_speed);
	game->dirY = oldDirX * sin(rot_speed) + game->dirY * cos(rot_speed);
	oldPlaneX = game->planeX;
	game->planeX = game->planeX * cos(rot_speed) - game->planeY * sin(rot_speed);
	game->planeY = oldPlaneX * sin(rot_speed) + game->planeY * cos(rot_speed);
}