#include "so_long.h"


int validate_map(char **map){
	if(!check_map(map))
		return 0;
	if(!check_chars(map))
		return 0;
	if(!check_elements(map))
		return 0;
	if(!check_walls(map))
		return 0;
	return 1;	
}

int check_map(char **map){
	int x;
	x = 0;
	if (!map || !map[x])
		return 0;
	size_t size = ft_strlen(map[x]);
	x++;
	while(map[x]){
		if(size != ft_strlen(map[x]))
			return 0;
		x++;
	}
	if(x < 3)
		return 0;
	return 1;
}

int check_chars(char **map){
	int x;
	int y;
	int i;
	i = 0;
	x = 0;
	while(map[x]){
		y = ft_strlen(map[x]);
		while(i < y){
			if(map[x][i] != 'P' && map[x][i] != 'E' && map[x][i] != 'C' && map[x][i] != '0' && map[x][i] != '1')
				return 0;
			i++;
		}	
		x++;
		i = 0;
	}
	return 1;
}

int check_elements(char **map){
	int x;
	int y;
	int i;
	int counter[3] = {0};
	x = 0;
	while(map[x]){
		i = 0;
		y = ft_strlen(map[x]);
		while(i < y){
			if(map[x][i] == 'P')
				counter[0]++;
			else if(map[x][i] == 'E')
				counter[1]++;
			else if(map[x][i] == 'C')
				counter[2]++;
			i++;
		}
		x++;
	}
	if(counter[0] == 1 && counter[1] == 1 && counter[2] >= 1)
		return 1;
	return 0;
}

int check_walls(char **map){
	int x;
	int y;
	int i;
	x = 0;
	y = 0;
	while(map[x][y]){
		if(map[x][y] != '1')
			return 0;
		y++;
	}
	x++;
	y = 0;
	while (map[x]){
		i = ft_strlen(map[x]);
		if(map[x][0] != '1' || map[x][i-1] != '1')
			return 0;
		x++;
	}
	while(map[x-1][y]){
		if(map[x-1][y] != '1')
			return 0;
		y++;
	}
	return 1;
}
