#include "../../include/so_long.h"

char **read_map(char *path){

	int fd;
	char **map;
	char *line;
	char *new_line;
	int b_read;
	char c;
	fd = open(path, O_RDONLY);
	if(fd < 0)
		return (perror("Error opening map"), NULL);
	map = malloc(sizeof(char *) * 1);
	if(!map)
		return(perror("Error memory allocation"), close(fd), NULL);
	map[0] = NULL;
	line = ft_strdup("");
	if(!line)
		return(perror("Error memory allocation"), close(fd), free_map(map),NULL);
	b_read = read(fd, &c, 1);
	while(b_read > 0){
		if(c == '\n'){
			int res;
			res = append_line(&map, line);
			if(res == 0)
				return(perror("Error memory allocation"), close(fd),free_map(map), free(line), NULL);
			line = ft_strdup("");
			if(!line)
				return(close(fd), free_map(map), NULL);
		}else{
			new_line = append_char(line, c);
			if(!new_line)
				return(close(fd),free(line), free_map(map), NULL);
			free(line);
			line = new_line;
		}
		b_read = read(fd, &c, 1);
	}
	if(b_read < 0)
		return(perror("Error reading newline"), close(fd), free_map(map), free(line), NULL);
	if(line[0] != '\0'){
		int res;
		res = append_line(&map, line);
		if(!res)
			return(perror("Error memory allocation"), close(fd), free_map(map), NULL);
		
	}else
		free(line);
	close(fd);
	if(!map[0])
		return (free(map), NULL);
	return (map);
}

int append_line(char ***map, char *line){
	int count = 0;
	char **new_map;
	int i = 0;
	while((*map)[count])
		count++;
	new_map = malloc(sizeof(char *) * (count + 2));
	if(!new_map)
		return 0;
	while(i < count){
		new_map[i] = (*map)[i];
		i++;
	}
	new_map[i] = line;
	new_map[i+1] = NULL;
	free(*map);
	*map = new_map;
	return (1);
}

void free_map(char **map){
	int i;
	if(!map)
		return ;
	i = 0;
	while(map[i]){
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

char *append_char(char *line, char c){
	char *new_line;
	char buffer[2];
	buffer[0] = c;
	buffer[1] = '\0';
	new_line = ft_strjoin(line, buffer);
	return (new_line);
}
