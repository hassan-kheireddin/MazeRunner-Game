/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:16 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:46:59 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_rec_shape(t_game *game)
{
	size_t	i;
	size_t	len;

	len = game->map.column;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != ft_strlen(game->map.map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	union_check(t_game *game)
{
	if (check_rec_shape(game) == 0)
		error_free_msg(game, "Error : Invalid map shape");
	check_count_element(game);
	if (check_border(&game->map) == 0)
		error_free_msg(game, "Error : Invalid map borders");
	check_path(game);
}
