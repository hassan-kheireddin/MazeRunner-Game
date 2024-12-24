/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:13:56 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:47:20 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.row = 0,
		.map.column = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.block.collectibles = NULL,
		.block.exit = NULL,
		.block.floor = NULL,
		.block.player = NULL,
		.block.wall = NULL,
		.moves = -1,
	});
}
