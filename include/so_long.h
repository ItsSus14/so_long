#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "ft_printf.h"
typedef struct	s_game{
	void	*mlx;
	void	*win;
	void	*image_floor;
	void	*image_collect;
	void	*image_player;
	void	*image_exit;
	void	*image_wall;
	int	player_x;
	int	player_y;
	int	map_width;
	int	map_height;
	char	**map;
	int	collectibles;
	int	moves;
}	t_game;

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
void	close_game(t_game *game);
int	handle_key(int key_code, void *param);
void	draw_map(t_game *game);
void	*convert_image(t_game *game, char *path);
int	set_images(t_game *game);
void	destroy_images(t_game *game);
int	move_player(t_game *game, int x, int y);
void	set_player_pos(t_game *game);
int	init_game(t_game *game, char *map);
void	count_collectibles(t_game *game);
void	free_game(t_game *game);

#endif
