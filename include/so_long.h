#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	**read_map(char *path);
char	*append_char(char *line, char c);
int	append_line(char ***map, char *line);
void	free_map(char **map);
int	check_walls(char **map);
int	validate_map(char **map);
int	check_map(char **map);
int	check_chars(char **map);
int	check_elements(char **map);
int	check_path(char **map);
int	*find_player(char **map);
char	**dup_map(char **map);
void	flood_fill(char **map, int x, int y);

#endif
