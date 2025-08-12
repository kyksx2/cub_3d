/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:10:22 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 18:05:35 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate(t_data *cube, double rot)
{
	float	cos_r;
	float	sin_r;
	float	old_cameraplane;

	cos_r = cos(rot);
	sin_r = sin(rot);
	old_cameraplane = cube->fov_raycast.cameraPlaneX;
	cube->fov_raycast.cameraPlaneX = cube->fov_raycast.cameraPlaneX * cos_r
		- cube->fov_raycast.cameraPlaneY * sin_r;
	cube->fov_raycast.cameraPlaneY = old_cameraplane * sin_r
		+ cube->fov_raycast.cameraPlaneY * cos_r;
	cube->player.angle += rot;
}

void	move_up(t_data *cube, double speed)
{
	t_player	*player;
	float		next_x;
	float		next_y;

	player = &cube->player;
	next_x = player->x + cos(player->angle) * speed;
	next_y = player->y + sin(player->angle) * speed;
	if (!touch(next_x, next_y, cube))
	{
		player->x = next_x;
		player->y = next_y;
	}
}

void	move_down(t_data *cube, double speed)
{
	t_player	*player;
	float		next_x;
	float		next_y;

	player = &cube->player;
	next_x = player->x - cos(player->angle) * speed;
	next_y = player->y - sin(player->angle) * speed;
	if (!touch(next_x, next_y, cube))
	{
		player->x = next_x;
		player->y = next_y;
	}
}

void	move_left(t_data *cube, double speed)
{
	t_player	*player;
	float		next_x;
	float		next_y;

	player = &cube->player;
	next_x = player->x + sin(player->angle) * speed;
	next_y = player->y - cos(player->angle) * speed;
	if (!touch(next_x, next_y, cube))
	{
		player->x = next_x;
		player->y = next_y;
	}
}

void	move_right(t_data *cube, double speed)
{
	t_player	*player;
	float		next_x;
	float		next_y;

	player = &cube->player;
	next_x = player->x - sin(player->angle) * speed;
	next_y = player->y + cos(player->angle) * speed;
	if (!touch(next_x, next_y, cube))
	{
		player->x = next_x;
		player->y = next_y;
	}
}
