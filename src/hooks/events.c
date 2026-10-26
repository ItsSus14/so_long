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
	else if (keycode == 119 || keycode == 65362){
		move_player(game, game->player_x, game->player_y - 1);
		draw_map(game);	
	}
	else if (keycode == 97 || keycode == 65361){
		move_player(game, game->player_x - 1, game->player_y);
		draw_map(game);
	}
	else if (keycode == 115 || keycode == 65364){
		move_player(game, game->player_x, game->player_y + 1);
		draw_map(game);
        }
	else if (keycode == 100 || keycode == 65363){
		move_player(game, game->player_x + 1, game->player_y);
		draw_map(game);
	}
	return (0);
}

int	move_player(t_game *game, int x, int y){
	if(game->map[y][x] == '1')
		return (0);
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_y = y;
	game->player_x = x;
	return 1;
}

void    draw_map(t_game *game)
{
	int     row;
	int     col;
	int     square_size;
	void	*img;

	row = 0;
	square_size = 64;
	while (game->map[row]){
		col = 0;
		while (game->map[row][col]){
			if (game->map[row][col] == '1')
                		img = game->image_wall;
			else if (game->map[row][col] == 'P')
				img = game->image_player;
			else if (game->map[row][col] == 'E')
				img = game->image_exit;
			else if (game->map[row][col] == 'C')
				img = game->image_collect;
			else
				img = game->image_floor;
		mlx_put_image_to_window(game->mlx, game->win, img, col * square_size, row * square_size);
			col++;
		}
		row++;
	}
}

