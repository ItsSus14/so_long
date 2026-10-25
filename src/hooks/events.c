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

void    draw_map(t_game *game, char **map)
{
	int     row;
	int     col;
	int     square_size;
	void	*img;

	row = 0;
	square_size = 64;
	while (map[row]){
		col = 0;
		while (map[row][col]){
			if (map[row][col] == '1')
                		img = game->image_wall;
			else if (map[row][col] == 'P')
				img = game->image_player;
			else if (map[row][col] == 'E')
				img = game->image_exit;
			else if (map[row][col] == 'C')
				img = game->image_collect;
			else
				img = game->image_floor;
		mlx_put_image_to_window(game->mlx, game->win, img, col * square_size, row * square_size);
			col++;
		}
		row++;
	}
}

