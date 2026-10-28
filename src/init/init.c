#include "so_long.h"

int	init_game(t_game *game, char *map){

	int i;
	i = 0;
	game->map = read_map(map);
	if(!game->map){
		write(2, "Error\nCould not read map\n", 25);
		return (1);
	}
	if(!validate_map(game->map)){
		write(2, "Error\nInvalid map\n", 18);
		return (1);
	}
	set_player_pos(game);
	count_collectibles(game);
	game->map_width = ft_strlen(game->map[i]);
	while(game->map[i])
		i++;
	game->map_height = i;
	game->moves = 0;
	return 0;
}

void	count_collectibles(t_game *game){
	int col;
	int row;
	int count;
	row = 0;
	count = 0;
	while(game->map[row]){
		col = 0;
		while(game->map[row][col]){
			if(game->map[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	game->collectibles = count;
}

void	free_game(t_game *game){
	free_map(game->map);
	game->map = NULL;
}
