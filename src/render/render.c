#include "so_long.h"

void *convert_image(t_game *game, char *path){

	void *image;
	int width;
	int height;
	
	image = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if(!image)
		return NULL;
	return image;
}

void set_player_pos(t_game *game){
	int x;
	int y;
	y = 0;
	while(game->map[y]){
		x = 0;
		while(game->map[y][x]){
			if(game->map[y][x] == 'P'){
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int set_images(t_game *game){
	game->image_floor = NULL;
	game->image_collect = NULL;
	game->image_exit = NULL;
	game->image_player = NULL;
	game->image_wall = NULL;
	game->image_floor = convert_image(game, "textures/floor.xpm");
	if(!game->image_floor){
		destroy_images(game);
		return (0);
	}
	game->image_collect = convert_image(game, "textures/collect.xpm");
	if(!game->image_collect){
		destroy_images(game);
		return (0);
	}
	game->image_exit = convert_image(game, "textures/exit.xpm");
	if(!game->image_exit){
		destroy_images(game);
		return (0);
	}
	game->image_player = convert_image(game, "textures/player.xpm");
	if(!game->image_player){
		destroy_images(game);
		return (0);
	}
	game->image_wall = convert_image(game, "textures/wall.xpm");
	if(!game->image_wall){
		destroy_images(game);
		return (0);
	}
	return (1);
}

void destroy_images(t_game *game){
	if(game->image_floor){
		mlx_destroy_image(game->mlx, game->image_floor);
		game->image_floor = NULL;
	}
	if(game->image_collect){
		mlx_destroy_image(game->mlx, game->image_collect);
		game->image_collect = NULL;
	}
	if(game->image_player){
		mlx_destroy_image(game->mlx, game->image_player);
		game->image_player = NULL;
	}
	if(game->image_exit){
		mlx_destroy_image(game->mlx, game->image_exit);
		game->image_exit = NULL;
	}
	if(game->image_wall){
		mlx_destroy_image(game->mlx, game->image_wall);
		game->image_wall = NULL;
	}
}


