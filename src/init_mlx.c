/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:03:46 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 08:08:27 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		error_free_msg(game, "Error : failed to initialize mlx");
	game->mlx_wind = mlx_new_window(game->mlx_init,
			game->map.column * BLOCK_SIZE,
			game->map.row * BLOCK_SIZE, "so_long");
	if (!game->mlx_wind)
		error_free_msg(game, "Error : Failed to open new window");
}
