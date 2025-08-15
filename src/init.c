/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:22:19 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/15 15:00:32 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// playerDirX = cos(player->angle);
// playerDirY = sin(player->angle);
void	init_fov(t_fov *fov, t_player *player)
{
	fov->fov_radian = FOV * (M_PI / 180.0f);
	fov->camera_planelenght = tan(fov->fov_radian / 2.0f);
	fov->camera_planex = -sin(player->angle) * fov->camera_planelenght;
	fov->camera_planey = cos(player->angle) * fov->camera_planelenght;
}

void	init_player_at_pos(t_data *cube, int x, int y)
{
	cube->player.x = (x + 0.5) * 64;
	cube->player.y = (y + 0.5) * 64;
	if (cube->x_file.map[y][x] == 'N')
		cube->player.angle = 3 * M_PI / 2;
	else if (cube->x_file.map[y][x] == 'S')
		cube->player.angle = M_PI / 2;
	else if (cube->x_file.map[y][x] == 'E')
		cube->player.angle = 0;
	else if (cube->x_file.map[y][x] == 'W')
		cube->player.angle = M_PI;
	cube->x_file.map[y][x] = '0';
}

void	init_player(t_data *cube)
{
	int	y;
	int	x;

	y = 0;
	while (cube->x_file.map[y])
	{
		x = 0;
		while (cube->x_file.map[y][x])
		{
			if (cube->x_file.map[y][x] == 'N' || cube->x_file.map[y][x] == 'S'
				|| cube->x_file.map[y][x] == 'E'
				|| cube->x_file.map[y][x] == 'W')
				init_player_at_pos(cube, x, y);
			x++;
		}
		y++;
	}
	init_fov(&cube->fov_raycast, &cube->player);
}

int	init_game(t_data *cube)
{
	if (!cube)
		return (0);
	cube->mlx = mlx_init();
	if (!cube->mlx)
		print_error(NULL, "mlx init.", 1);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "cub_3d");
	if (!cube->win)
		print_error(NULL, "mlx init.", 1);
	cube->main_img.img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->main_img.img)
		print_error(cube, "Erreur image.", 1);
	cube->main_img.data = mlx_get_data_addr(cube->main_img.img,
			&cube->main_img.bpp, &cube->main_img.line_len,
			&cube->main_img.endian);
	if (!cube->main_img.data)
		print_error(cube, "image data.", 1);
	load_img(cube, &cube->texture[0], cube->x_file.text_no);
	load_img(cube, &cube->texture[1], cube->x_file.text_so);
	load_img(cube, &cube->texture[2], cube->x_file.text_we);
	load_img(cube, &cube->texture[3], cube->x_file.text_ea);
	return (1);
}

void	init_ray(t_data *cube)
{
	cube->raycasting.delta_distx = 0;
	cube->raycasting.delta_disty = 0;
	cube->raycasting.map_x = 0;
	cube->raycasting.map_y = 0;
	cube->raycasting.prepwallwist = 0;
	cube->raycasting.ray_dirx = 0;
	cube->raycasting.ray_diry = 0;
	cube->raycasting.side_distx = 0;
	cube->raycasting.side_disty = 0;
	cube->raycasting.step_x = 0;
	cube->raycasting.step_y = 0;
	cube->raycasting.height = 0;
	cube->raycasting.drawstart = 0;
	cube->raycasting.drawend = 0;
}

// static void	init_data(t_data *cube, char *file)
// {
// 	int	i;
// 	i = 0;
// 	cube->file = file;
// 	cube->height = 0;
// 	cube->width = 0;	
// 	cube->count_player = 0;
// 	cube->mlx = NULL;
// 	cube->win = NULL;
// 	cube->main_img.img = NULL;
// 	cube->main_img.data = NULL;
// 	while (i < 4)
// 	{
// 		cube->texture[i].img = NULL;
// 		cube->texture[i].data = NULL;
// 		i++;
// 	}
// 	cube->x_file.map = NULL;
// 	cube->x_file.color_c = 0;
// 	cube->x_file.color_f = 0;
// 	cube->x_file.text_ea = NULL;
// 	cube->x_file.text_no = NULL;
// 	cube->x_file.text_so = NULL;
// 	cube->x_file.text_we = NULL;
// }