#include "so_long.h"
#include "mlx.h"

void close_game(t_game *game){
	mlx_loop_end(game->mlx);
}

int handle_key(int keycode, void *param){
	t_game *game;
	game = (t_game *)param;
	if(keycode == 65307)
		close_game(game);
	else if(keycode == 119 || keycode == 65362)
		draw_square(game, 0, 0, 100, 0xFF0000);
	else if(keycode == 97 || keycode == 65361)
		draw_square(game, 100, 100, 100, 0xFFFF00);
	else if(keycode == 115 || keycode == 65364)
		printf("down\n");
	else if(keycode == 100 || keycode == 65363)
		printf("right\n");
	return (0);
}

void    draw_square(t_game *game, int x, int y, int size, int color)
{
	int i;
	int j;
	i = 0;
	while (i < size){
		j = 0;
		while (j < size){
			mlx_pixel_put(game->mlx, game->win, i+x, j+y, color);
			j++;
		}
		i++;
	}
}

