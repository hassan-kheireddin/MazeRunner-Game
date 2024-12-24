/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:03:49 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:46:29 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "blocks.h"
# include ".././libft/includes/ft_printf.h"
# include ".././libft/includes/get_next_line.h"
# include ".././libft/includes/libft.h"
# include ".././mlx/mlx.h"

typedef struct s_position {
	int		x;
	int		y;
}	t_position;

typedef struct s_block {
	void	*exit;
	void	*collectibles;
	void	*player;
	void	*wall;
	void	*floor;
}	t_block;

typedef struct s_map {
	char			**map;
	int				row;
	int				column;
	int				collectibles;
	int				player;
	int				exit;
	t_position		player_position;
}	t_map;

typedef struct s_game {
	void	*mlx_init;
	void	*mlx_wind;
	int		moves;
	t_block	block;
	t_map	map;
}	t_game;

int		check_border(t_map *map);
int		check_file_extension(char *map_file);
void	check_e_c_p(t_game *game);
int		check_str(char *str, int c);
void	check_count_element(t_game *game);
int		check_rec_shape(t_game *game);
void	union_check(t_game *game);
char	**copy_map(t_game *game);
int		flood_fill(t_map *map, t_position curr, char **temp_map);
void	check_path(t_game *game);
void	free_blocks(t_game *game);
void	free_matrix(char **matrix);
void	error_free(t_game *game);
void	error_free_msg(t_game *game, char *error_msg);
void	get_row(char *map_file, t_game *game);
void	read_row(char *map_file, t_game *game);
void	get_map(char *file_map, t_game *game);
t_game	init_game(void);
void	init_mlx(t_game *game);
int		quit_game(t_game *game);
int		on_press(int key, t_game *game);
void	hook_n_run(t_game *game);
void	put_player_block(t_game *game);
void	which_block(t_game *game);
void	update_left_behind_block(t_game *game);
void	update_player_pos(t_game *game, bool horizontal, int length);
void	error_xpm(t_game *game);
void	xpm_to_image(t_game *game);
void	img_to_window(t_game *game);
void	render_map(t_game *game);
char	*trim_free(char *s1, char const *set);

#endif
