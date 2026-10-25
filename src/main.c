#include "so_long.h"
#include "mlx.h"

/*int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (write(2, "Error\nUsage: ./so_long <map.ber>\n", 33), 1);
	map = read_map(argv[1]);
	if (!map)
		return (write(2, "Error\nCould not read map\n", 25), 1);
	if (!validate_map(map))
	{
		write(2, "Error\nInvalid map\n", 18);
		free_map(map);
		return (1);
	}
	if (!check_path(map))
	{
		write(2, "Error\nInvalid path\n", 19);
		free_map(map);
		return (1);
	}
	write(1, "Map is valid!\n", 14);
	free_map(map);
	return (0);
}*/

int	main(int argc, char **argv)
{
	(void) argc;
	t_game game;
	char **map;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	map = read_map(argv[1]);
	if (!map)
		return (write(2, "Error\nCould not read map\n", 25), 1);
	int x = ft_strlen(map[0]);
	int y = 0;
	while(map[y])
		y++;
	game.win = mlx_new_window(game.mlx, (x * 64), (y *64), "so_long");
	if(!set_images(&game)){
		return (1);
	}
	draw_map(&game, map);
	if (!game.win){
		free(game.mlx);
		free(game.image_floor);
		return (1);
	}
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	return (0);
}

