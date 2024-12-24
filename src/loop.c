/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:33:13 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:47:27 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	quit_game(t_game *game)
{
	error_free(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == 65307)
		quit_game(game);
	else if (key == 119 || key == 65362)
		update_player_pos(game, false, -1);
	else if (key == 97 || key == 65361)
		update_player_pos(game, true, -1);
	else if (key == 115 || key == 65364)
		update_player_pos(game, false, 1);
	else if (key == 100 || key == 65363)
		update_player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->mlx_wind, 2, (1L << 0), on_press, game);
	mlx_hook(game->mlx_wind, 17, (1L << 17),
		quit_game, game);
	mlx_loop(game->mlx_init);
}
