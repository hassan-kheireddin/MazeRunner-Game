/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:23:06 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:46:48 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_border(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->row)
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (0);
	i = -1;
	while (++i < map->column)
		if (map->map[0][i] != '1' || map->map[map->row - 1][i] != '1')
			return (0);
	return (1);
}

int	check_file_extension(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

void	check_e_c_p(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		error_free_msg(game, "Error : Invalid number of exit block");
	if (game->map.player == 0 || game->map.player > 1)
		error_free_msg(game, "Error : Invalid number of start block");
	if (game->map.collectibles == 0)
		error_free_msg(game, "Error : Invalid number of collectibles block");
}

int	check_str(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_count_element(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.column)
		{
			if (check_str("ECP01", game->map.map[i][j]) == 0)
				error_free_msg(game, "Error : Invalid entity on map");
			if (game->map.map[i][j] == 'E')
				game->map.exit += 1;
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles += 1;
			else if (game->map.map[i][j] == 'P')
			{
				game->map.player += 1;
				game->map.player_position = (t_position){j, i};
			}
		}
	}
	check_e_c_p(game);
}
