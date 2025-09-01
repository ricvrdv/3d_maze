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

    double  wallX;          // Exact hit point on the wall
    int     texX;           // Texture X coordinate
    double  texPos;         // Texture position
    double  step;           // Texture step size
    int     texY;           // Texture Y coordinate
    int     color;          // Pixel color from texture
    t_img   *current_tex;   // Pointer to current texture

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
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        // 1. Calculate exact wall hit point
        if (side == 0) // X-side hit (EAST/WEST wall)
            wallX = game->posY + perpWallDist * rayDirY;
        else // Y-side hit (NORTH/SOUTH wall)
            wallX = game->posX + perpWallDist * rayDirX;
        wallX -= floor(wallX); // Get fractional part (0.0 to 1.0)

        // 2. Determine which texture to use based on wall direction
        if (side == 1) // Hit a Y-side wall
        {
            if (rayDirY > 0) // Ray was going DOWN (South-facing wall)
                current_tex = &game->so_texture;
            else // Ray was going UP (North-facing wall)
                current_tex = &game->no_texture;
        }
        else // Hit an X-side wall
        {
            if (rayDirX > 0) // Ray was going RIGHT (East-facing wall)
                current_tex = &game->ea_texture;
            else // Ray was going LEFT (West-facing wall)
                current_tex = &game->we_texture;
        }

        // 3. Calculate texture X coordinate
        texX = (int)(wallX * (double)current_tex->width);
        if ((side == 0 && rayDirX > 0) || (side == 1 && rayDirY < 0))
            texX = current_tex->width - texX - 1;

        // 4. Calculate texture stepping
        step = 1.0 * current_tex->height / lineHeight;
        texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;

        // 5. Draw the textured vertical stripe
        for (int y = drawStart; y < drawEnd; y++)
        {
            // Calculate texture Y coordinate
            texY = (int)texPos & (current_tex->height - 1);
            texPos += step;

            // Get color from texture
            color = get_texture_pixel(current_tex, texX, texY);
            
            // Apply shading for Y-side walls (optional)
            //if (side == 1)
            //    color = (color >> 1) & 0x7F7F7F;
            
            // Draw the pixel
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