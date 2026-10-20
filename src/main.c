#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 25);
		return (1);
	}
	map = read_map(argv[1]);
	if (!map)
	{
		write(2, "Error\nInvalid map file\n", 23);
		return (1);
	}
	if (!validate_map(map)){
		write(2, "Error\nInvalid map\n", 18);
		free_map(map);
		return (1);
	}
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	free_map(map);
	return (0);
}
