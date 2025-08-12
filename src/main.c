/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:04:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 18:15:06 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	endgame(t_data *cube)
{
	free_cube(cube);
	exit(0);
}

int	bad_args(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i <= 4)
		return (1);
	if (ft_strncmp((av + i - 4), ".cub", 4) != 0)
		return (1);
	return (0);
}

void	init_all(t_data *init, char *file)
{
	memset(init, 0, sizeof(t_data));
	init->file = file;
	open_map(init);
	init_game(init);
	init_player(init);
	init_ray(init);
}

int	main(int ac, char **av)
{
	t_data	cube;
	t_list	*read_map;

	if (ac < 2 || bad_args(av[1]))
		print_error(NULL, "mauvais argument.", 1);
	read_map = NULL;
	init_all(&cube, av[1]);
	mlx_hook(cube.win, 2, 1L << 0, key_action, &cube);
	mlx_loop_hook(cube.mlx, execution, &cube);
	mlx_hook(cube.win, 17, 0, endgame, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
