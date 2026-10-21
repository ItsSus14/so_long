#include "so_long.h"

int	check_path(char **map){
	int *player;
	char **copy_map;
	int i;
	int y;
	copy_map = dup_map(map); 
	if(!copy_map)
		return 0;
	player = find_player(map);
	if(!player){
		free_map(copy_map);
		return 0;
	}
	flood_fill(copy_map, player[0], player[1]);
	free(player);
	i = 0;
	while(copy_map[i]){
		y = 0;
		while(copy_map[i][y]){
			if(copy_map[i][y] == 'P' || copy_map[i][y] == 'C' || copy_map[i][y] == 'E'){
				free_map(copy_map);
				return 0;
			}
			y++;
		}
		i++;
	}
	free_map(copy_map);
	return 1;
}

int	*find_player(char **map){
	size_t x;
	size_t y;
	size_t i;
	int *player;
	player = malloc(sizeof(int) * 2);
	if(!player)
		return NULL;
	x = 0;
	while(map[x]){
		i = 0;
		y = ft_strlen(map[x]);
		while(i < y){
			if(map[x][i] == 'P'){
				player[0] = (int)x;
				player[1] = (int)i;
				return player;
			}
			i++;
		}
		x++;
	}
	free(player);
	return NULL;
}

char **dup_map(char **map){
	int i;
	char **copy_map;
	int rows;
	rows = 0;
	if(!map)
		return NULL;
	while(map[rows]){
		rows++;
	}
	copy_map = malloc(sizeof(char *) * (rows + 1));
	if(!copy_map)
		return NULL;
	i = 0;
	while (i <= rows){
		copy_map[i] = NULL;
		i++;
	}
	i = 0;
	while(map[i]){
		copy_map[i] = ft_strdup(map[i]);
		if(!copy_map[i]){
			free_map(copy_map);
			return NULL;			
		}
		i++;
	}
	return copy_map;
}

/*
 * Esplora ricorsivamente tutte le caselle raggiungibili,
 * segnando quelle visitate con '1' per evitare ripetizioni
 * e fermandosi quando incontra muri o limiti della mappa.
 */
void flood_fill(char **map, int x, int y){
	int height;
	int width;
	height = 0;
	width = ft_strlen(map[0]);
	while(map[height])
		height++;
	if(x < 0 || x >= height || y < 0 || y >= width)
		return;
	if(map[x][y] == '1')
		return;
	map[x][y] = '1';
	flood_fill(map, x+1, y);
	flood_fill(map, x-1, y);
	flood_fill(map, x, y+1);
	flood_fill(map, x, y-1);
}
