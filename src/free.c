/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:45:26 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:47:10 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_blocks(t_game *game)
{
	if (game->block.exit)
		mlx_destroy_image(game->mlx_init, game->block.exit);
	if (game->block.collectibles)
		mlx_destroy_image(game->mlx_init, game->block.collectibles);
	if (game->block.player)
		mlx_destroy_image(game->mlx_init, game->block.player);
	if (game->block.wall)
		mlx_destroy_image(game->mlx_init, game->block.wall);
	if (game->block.floor)
		mlx_destroy_image(game->mlx_init, game->block.floor);
}

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	if (i > 0)
		free(matrix);
	matrix = NULL;
}

void	error_free(t_game *game)
{
	if (!game)
		return ;
	free_blocks(game);
	if (game->mlx_wind)
		mlx_destroy_window(game->mlx_init, game->mlx_wind);
	if (game->mlx_init)
	{
		mlx_destroy_display(game->mlx_init);
		free(game->mlx_init);
	}
	if (game->map.map)
		free_matrix(game->map.map);
}

void	error_free_msg(t_game *game, char *error_msg)
{
	error_free(game);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
