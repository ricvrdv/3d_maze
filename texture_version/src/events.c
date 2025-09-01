#include "../inc/game.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    else if (keycode == KEY_W)
        game->key_w = true;
    else if (keycode == KEY_A)
        game->key_a = true;
    else if (keycode == KEY_S)
        game->key_s = true;
    else if (keycode == KEY_D)
        game->key_d = true;
    else if (keycode == KEY_LEFT)
        game->key_left = true;
    else if (keycode == KEY_RIGHT)
        game->key_right = true;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        game->key_w = false;
    else if (keycode == KEY_A)
        game->key_a = false;
    else if (keycode == KEY_S)
        game->key_s = false;
    else if (keycode == KEY_D)
        game->key_d = false;
    else if (keycode == KEY_LEFT)
        game->key_left = false;
    else if (keycode == KEY_RIGHT)
        game->key_right = false;
    return (0);
}

void handle_movement(t_game *game)
{
    double moveX;
    double moveY;
    double rotSpeed;

    moveX = 0;
	moveY = 0;
	rotSpeed = 0;
    if (game->key_w)
	{
		moveX += game->dirX * game->move_speed;
		moveY += game->dirY * game->move_speed;
	}
    if (game->key_s)
	{
		moveX -= game->dirX * game->move_speed;
		moveY -= game->dirY * game->move_speed;
	}
    if (game->key_a)
	{
		moveX -= game->dirY * game->move_speed;
		moveY += game->dirX * game->move_speed;
	}
    if (game->key_d)
	{
		moveX += game->dirY * game->move_speed;
		moveY -= game->dirX * game->move_speed;
	}
    if (game->key_left) 
		rotSpeed += game->rot_speed;
    if (game->key_right)
		rotSpeed -= game->rot_speed;
    if (rotSpeed != 0)
        rotate_player(game, rotSpeed);
    if (moveX != 0 || moveY != 0)
    {
        if (game->map[(int)(game->posY)][(int)(game->posX + moveX)] == 0)
            game->posX += moveX;
        if (game->map[(int)(game->posY + moveY)][(int)(game->posX)] == 0)
            game->posY += moveY;
    }
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