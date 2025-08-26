#include "../inc/game.h"

void    load_textures(t_game *game)
{
    int i;

    char    *texture_files[NUM_TEXTURES] = {
        "textures/north.xpm",
        "textures/south.xpm",
        "textures/east.xpm",
        "textures/west.xpm"
    };

    i = 0;
    while (i < NUM_TEXTURES)
    {
        game->textures[i].img = mlx_xpm_file_to_image(game->mlx, texture_files[i],
            &game->textures[i].width, &game->textures[i].height);
        if (!game->textures[i].img)
        {
            printf("Error: Could not load texture %s\n", texture_files[i]);
            exit(1);
        }
		printf("Loaded texture %s: %dx%d\n", texture_files[i], 
               game->textures[i].width, game->textures[i].height);
		i++;
    }
    game->floor_color = 0x383838;
	game->ceiling_color = 0x87CEEB;
}