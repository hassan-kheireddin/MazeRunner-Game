/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:40:09 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:47:03 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**copy_map(t_game *game)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_calloc(game->map.row + 1, sizeof(char *));
	if (!temp)
		error_free_msg(game, "Calloc() err");
	while (i < game->map.row)
	{
		temp[i] = ft_strdup(game->map.map[i]);
		if (!temp[i])
		{
			free_matrix(temp);
			error_free_msg(game, "Malloc() err");
		}
		i++;
	}
	return (temp);
}

int	flood_fill(t_map *map, t_position curr, char **temp_map)
{
	static int	collectibles = 0;
	static int	exit = 0;

	if (temp_map[curr.y][curr.x] == '1')
		return (0);
	else if (temp_map[curr.y][curr.x] == 'E')
		exit = 1;
	else if (temp_map[curr.y][curr.x] == 'C')
		collectibles += 1;
	temp_map[curr.y][curr.x] = '1';
	flood_fill(map, (t_position){curr.x + 1, curr.y}, temp_map);
	flood_fill(map, (t_position){curr.x - 1, curr.y}, temp_map);
	flood_fill(map, (t_position){curr.x, curr.y + 1}, temp_map);
	flood_fill(map, (t_position){curr.x, curr.y - 1}, temp_map);
	return (collectibles == map->collectibles && exit);
}

void	check_path(t_game *game)
{
	char	**temp_map;

	temp_map = copy_map(game);
	if (flood_fill(&game->map, game->map.player_position, temp_map) == 0)
	{
		free_matrix(temp_map);
		error_free_msg(game, "Error : Invalid path");
	}
	free_matrix(temp_map);
}
