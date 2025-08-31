#include "../inc/game.h"

int main_loop(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            my_mlx_pixel_put(&game->img, x, y, 0x000000);
            x++;
        }
        y++;
    }
    raycast(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
    return (0);
}

void    raycast(t_game *game)
{
    int     x;
    double  cameraX;
    double  rayDirX;
    double  rayDirY;
    int     mapX;
    int     mapY;
    double  deltaDistX;
    double  deltaDistY;
    double  sideDistX;
    double  sideDistY;
    int     stepX;
    int     stepY;
    int     hit;
    int     side; // side = 0 if hit X-side, side = 1 if hit Y-side
    double  perpWallDist;
    int     lineHeight;
    int     drawStart;
    int     drawEnd;
    int     color;

    x = 0;
    while (x < SCREEN_WIDTH)
    {
        cameraX = 2 * x / (double)SCREEN_WIDTH -1;
        rayDirX = game->dirX + game->planeX * cameraX;
        rayDirY = game->dirY + game->planeY * cameraX;
        mapX = (int)game->posX;
        mapY = (int)game->posY;
        if (rayDirX == 0)
            deltaDistX = 1e30;
        else
            deltaDistX = fabs(1 / rayDirX);
        if (rayDirY == 0)
            deltaDistY = 1e30;
        else
            deltaDistY = fabs(1 / rayDirY);
        hit = 0;
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (game->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (game->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->posY) * deltaDistY;
        }
        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (game->map[mapY][mapX] > 0)
                hit = 1;
        }
        if (side == 0)
            perpWallDist = sideDistX - deltaDistX;
        else
            perpWallDist = sideDistY - deltaDistY;
        
        lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        
        drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

        x++;
    }
}