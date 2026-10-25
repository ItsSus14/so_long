#include "so_long.h"

void    close_game(t_game *game)
{
    mlx_loop_end(game->mlx);
}

int handle_key(int keycode, void *param)
{
	t_game  *game;

	game = (t_game *)param;
	if (keycode == 65307)
        	close_game(game);
	else if (keycode == 119 || keycode == 65362)
    		printf("up\n");
	else if (keycode == 97 || keycode == 65361)
		printf("left\n");
	else if (keycode == 115 || keycode == 65364)
        	printf("down\n");
	else if (keycode == 100 || keycode == 65363)
        	printf("right\n");
	return (0);
}

void    draw_square(t_game *game, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            mlx_pixel_put(game->mlx, game->win, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void    draw_map(t_game *game, char **map)
{
    int     row;
    int     col;
    int     tile_size;
    int     color;

    row = 0;
    tile_size = 64;
    while (map[row])
    {
        col = 0;
        while (map[row][col])
        {
            if (map[row][col] == '1')
                color = COLOR_WALL;
            else if (map[row][col] == 'P')
                color = COLOR_PLAYER;
            else if (map[row][col] == 'E')
                color = COLOR_EXIT;
            else if (map[row][col] == 'C')
                color = COLOR_COLLECT;
            else
                color = COLOR_FLOOR;
            draw_square(game, col * tile_size, row * tile_size,
                tile_size, color);
            col++;
        }
        row++;
    }
}

