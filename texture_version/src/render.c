#include "../inc/game.h"

int main_loop(t_game *game)
{
    handle_movement(game);
    draw_floor_ceiling(game);
    raycast(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
    return (0);
}

void    raycast(t_game *game)
{
    t_player    *player;
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
    int     side;
    double  perpWallDist;
    int     lineHeight;
    int     drawStart;
    int     drawEnd;

    double  wallX;
    int     texX;
    double  texPos;
    double  step;
    int     texY;
    int     color;
    t_img   *current_tex;

    player = &game->player;
    x = 0;
    while (x < SCREEN_WIDTH)
    {
        cameraX = 2 * x / (double)SCREEN_WIDTH -1;
        rayDirX = player->dirX + player->planeX * cameraX;
        rayDirY = player->dirY + player->planeY * cameraX;
        mapX = (int)player->posX;
        mapY = (int)player->posY;
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
            sideDistX = (player->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
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
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;
        if (side == 0)
            wallX = player->posY + perpWallDist * rayDirY;
        else
            wallX = player->posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);
        if (side == 1)
        {
            if (rayDirY > 0)
                current_tex = &game->so_texture;
            else
                current_tex = &game->no_texture;
        }
        else
        {
            if (rayDirX > 0)
                current_tex = &game->ea_texture;
            else
                current_tex = &game->we_texture;
        }

        texX = (int)(wallX * (double)current_tex->width);
        if ((side == 0 && rayDirX > 0) || (side == 1 && rayDirY < 0))
            texX = current_tex->width - texX - 1;

        step = 1.0 * current_tex->height / lineHeight;
        texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;

        for (int y = drawStart; y < drawEnd; y++)
        {
            texY = (int)texPos & (current_tex->height - 1);
            texPos += step;
            color = get_texture_pixel(current_tex, texX, texY);
            
            // Apply shading for Y-side walls (optional)
            //if (side == 1)
            //    color = (color >> 1) & 0x7F7F7F;
            my_mlx_pixel_put(&game->img, x, y, color);
        }
        x++;
    }
}

int get_texture_pixel(t_img *texture, int x, int y)
{
    char *pixel;
    
    if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
        return (0);
    
    pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    return (*(int *)pixel);
}

void    draw_vertical_line(t_game *game, int x, int start, int end, int color)
{
    while (start < end)
    {
        my_mlx_pixel_put(&game->img, x, start, color);
        start++;
    }
}