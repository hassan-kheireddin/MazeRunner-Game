/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:39:31 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:47:33 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	args_check(int argc, char **argv)
{
	if (argc != 2)
		error_free_msg(NULL, "Error Invalid number of args");
	if (*argv[1] == '\0')
		error_free_msg(NULL, "Map is null");
}

int	main(int argc, char **argv)
{
	t_game	game;

	args_check(argc, argv);
	game = init_game();
	get_map(argv[1], &game);
	union_check(&game);
	init_mlx(&game);
	render_map(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
