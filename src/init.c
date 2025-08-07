/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:22:19 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/07 17:30:21 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void    init_data(t_data *cube, char *file)
{
    cube->file = file;
    cube->height = 0;
    cube->width = 0;
	cube->count_player = 0;
	cube->x_file.map = NULL;
    cube->x_file.color_c = 0;
    cube->x_file.color_f = 0;
    cube->x_file.text_ea = NULL;
    cube->x_file.text_no = NULL;
    cube->x_file.text_so = NULL;
    cube->x_file.text_we = NULL;
}

static void	init_player(t_data *cube)
{
	int	y;
	int	x;

	y = 0;
	while(cube->x_file.map[y])
	{
		x = 0;
		while(cube->x_file.map[y][x])
		{
			if(cube->x_file.map[y][x] == 'N' || cube->x_file.map[y][x] == 'S' ||
				cube->x_file.map[y][x] == 'E' || cube->x_file.map[y][x] == 'W')
				{
					cube->player.x = (x + 0.5) * 64; // ? + 0.5 pour centrer
					cube->player.y = (y + 0.5) * 64;
					if(cube->x_file.map[y][x] == 'N')
						cube->player.angle = M_PI / 2;
					if(cube->x_file.map[y][x] == 'S')
						cube->player.angle = 3 * M_PI / 2;
					if(cube->x_file.map[y][x] == 'E')
						cube->player.angle = 0;
					if(cube->x_file.map[y][x] == 'W')
						cube->player.angle = M_PI;		
					cube->x_file.map[y][x] = '0';
				}
			x++;
		}
		y++;
	}
}

static int	init_game(t_data *cube)
{
	if (!cube)
		return (0);
	cube->mlx = mlx_init();
	if (!cube->mlx)
		print_error(NULL, "mlx init.", 1);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "cub_3d");
	if (!cube->win)
		print_error(NULL, "mlx init.", 1);
	cube->texture.img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->texture.img)
		print_error(cube, "Erreur image.", 1);
	cube->texture.data = mlx_get_data_addr(cube->texture.img,
		&cube->texture.bpp, &cube->texture.line_len, &cube->texture.endian);
	if (!cube->texture.data)
		print_error(cube, "Erreur image data.", 1);
 	mlx_put_image_to_window(cube->mlx, cube->win, cube->texture.img, 0, 0);
	return (1);
}

void	init_all(t_data *init, char *file)
{
	init_data(init, file);
	open_map(init);
	init_game(init);
	init_player(init);
}
