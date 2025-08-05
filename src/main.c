/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:04:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/05 19:34:32 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	endgame(t_data *cube)
{
	(void)cube;
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

void    init_data(t_data *cube, char *av)
{
    cube->file = ft_strdup(av);
    cube->height = 0;
    cube->mlx = NULL;
    cube->width = 0;
    cube->win = NULL;
	cube->count_player = 0;
	cube->x_file.map = NULL;
    cube->x_file.color_c = 0;
    cube->x_file.color_f = 0;
    cube->x_file.text_ea = NULL;
    cube->x_file.text_no = NULL;
    cube->x_file.text_so = NULL;
    cube->x_file.text_we = NULL;
	cube->player.angle = 0;
	cube->player.x = 0;
	cube->player.y = 0;
}

// void	init_player(t_data *cube)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while(cube->x_file.map[y])
// 	{
// 		x = 0;
// 		while(cube->x_file.map[y][x])
// 		{
// 			if(cube->x_file.map[y][x] == 'N' || cube->x_file.map[y][x] == 'S' ||
// 				cube->x_file.map[y][x] == 'E' || cube->x_file.map[y][x] == 'W')
// 				{
// 					cube->player.x = (x + 0.5) * CUB_PIXEL; // ? + 0.5 pour centrer
// 					cube->player.y = (y + 0.5) * CUB_PIXEL;
// 					if(cube->x_file.map[y][x] == 'N')
// 						cube->player.angle = M_PI / 2;
// 					if(cube->x_file.map[y][x] == 'S')
// 						cube->player.angle = 3 * M_PI / 2;
// 					if(cube->x_file.map[y][x] == 'E')
// 						cube->player.angle = 0;
// 					if(cube->x_file.map[y][x] == 'W')
// 						cube->player.angle = M_PI;		
// 					cube->x_file.map[y][x] = '0';
// 				}
// 			x++;
// 		}
// 		y++;
// 	}
// }

int main(int ac, char **av)
{
	t_data	cube;
	t_list	*read_map;

	if (ac < 2 || bad_args(av[1]))
		print_error(NULL, "mauvais argument.", 1);
	read_map = NULL;
	init_data(&cube, av[1]);
	open_map(&cube);
	// init_player(&cube);
	cube.mlx = mlx_init();
	if (!cube.mlx)
		print_error(NULL, "mlx init.", 1);
	cube.win = mlx_new_window(cube.mlx, 640, 480, "cub_3d");
	// mlx_loop_hook(cube.mlx, render, &cube);
	mlx_hook(cube.win, 2, 1L << 0, key_action, &cube);
	mlx_hook(cube.win, 17, 0, endgame, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
