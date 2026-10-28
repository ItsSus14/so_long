#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game game;
	if (argc != 2)
                  return (write(2, "Error\nUsage: ./so_long <map.ber>\n", 33), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	if(init_game(&game, argv[1])){
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_map(game.map);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, (game.map_width * 64), (game.map_height *64), "so_long");
	if (!game.win){
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_game(&game);
		return (1);
	}
	if(!set_images(&game)){
		mlx_destroy_window(game.mlx, game.win);
		mlx_destroy_display(game.mlx);
		free_game(&game);
		free(game.mlx);
		return (1);
	}
	draw_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	destroy_images(&game);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free_game(&game);
	free(game.mlx);
	return (0);
}

