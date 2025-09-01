#include "../inc/game.h"

int key_press(int keycode, t_game *game)
{
    t_player	*player;

	player = &game->player;
	if (keycode == KEY_ESC)
        exit_game(game);
    else if (keycode == KEY_W)
        player->key_w = true;
    else if (keycode == KEY_A)
        player->key_a = true;
    else if (keycode == KEY_S)
        player->key_s = true;
    else if (keycode == KEY_D)
        player->key_d = true;
    else if (keycode == KEY_LEFT)
        player->key_left = true;
    else if (keycode == KEY_RIGHT)
        player->key_right = true;
    return (0);
}

int key_release(int keycode, t_player *player)
{
    if (keycode == KEY_W)
        player->key_w = false;
    else if (keycode == KEY_A)
        player->key_a = false;
    else if (keycode == KEY_S)
        player->key_s = false;
    else if (keycode == KEY_D)
        player->key_d = false;
    else if (keycode == KEY_LEFT)
        player->key_left = false;
    else if (keycode == KEY_RIGHT)
        player->key_right = false;
    return (0);
}

void handle_movement(t_game *game)
{
    double moveX;
    double moveY;
    double rotSpeed;
	t_player	*player;

	player = &game->player;
    moveX = 0;
	moveY = 0;
	rotSpeed = 0;
    if (player->key_w)
	{
		moveX += player->dirX * player->move_speed;
		moveY += player->dirY * player->move_speed;
	}
    if (player->key_s)
	{
		moveX -= player->dirX * player->move_speed;
		moveY -= player->dirY * player->move_speed;
	}
    if (player->key_a)
	{
		moveX -= player->dirY * player->move_speed;
		moveY += player->dirX * player->move_speed;
	}
    if (player->key_d)
	{
		moveX += player->dirY * player->move_speed;
		moveY -= player->dirX * player->move_speed;
	}
    if (player->key_left) 
		rotSpeed += player->rot_speed;
    if (player->key_right)
		rotSpeed -= player->rot_speed;
    if (rotSpeed != 0)
        rotate_player(player, rotSpeed);
    if (moveX != 0 || moveY != 0)
    {
        if (game->map[(int)(player->posY)][(int)(player->posX + moveX)] == 0)
            player->posX += moveX;
        if (game->map[(int)(player->posY + moveY)][(int)(player->posX)] == 0)
            player->posY += moveY;
    }
}

void	rotate_player(t_player *player, double rot_speed)
{
	double  oldDirX;
    double  oldPlaneX;

    oldDirX = player->dirX;
	player->dirX = player->dirX * cos(rot_speed) - player->dirY * sin(rot_speed);
	player->dirY = oldDirX * sin(rot_speed) + player->dirY * cos(rot_speed);
	oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(rot_speed) - player->planeY * sin(rot_speed);
	player->planeY = oldPlaneX * sin(rot_speed) + player->planeY * cos(rot_speed);
}