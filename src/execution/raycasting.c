/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:39:15 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 21:26:28 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// playerDirX = cos(player->angle);
// playerDirY = sin(player->angle);
void	init_raycst(t_raycast *ray, t_fov *rct, t_player *player, float cameraX)
{
	ray->ray_dirx = cos(player->angle) + rct->camera_planex * cameraX;
	ray->ray_diry = sin(player->angle) + rct->camera_planey * cameraX;
	ray->map_x = (int)player->x / 64.0f;
	ray->map_y = (int)player->y / 64.0f;
	ray->delta_distx = fabs(1.0f / ray->ray_dirx);
	ray->delta_disty = fabs(1.0f / ray->ray_diry);
	ray->hit = 0;
}

void	dda_loop(t_raycast *ray, t_data *cube)
{
	while (ray->hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_distx;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_disty;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < cube->height
			&& ray->map_x >= 0 && ray->map_x < cube->width
			&& cube->x_file.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	crazy_diamond(t_raycast *ray)
{
	ray->height = (int)(HEIGHT / ray->prepwallwist);
	ray->drawstart = -ray->height / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->height / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
}

void	raycast(t_data *cube, float cameraX, int screenX)
{
	t_player	*player;
	t_fov		*rct;
	t_raycast	*ray;

	player = &cube->player;
	rct = &cube->fov_raycast;
	ray = &cube->raycasting;
	init_raycst(ray, rct, player, cameraX);
	calcul_dist_x(player, ray);
	calcul_dist_y(player, ray);
	dda_loop(ray, cube);
	if (ray->side == 0)
		ray->prepwallwist = (ray->map_x - (player->x / 64.0f)
				+ (1 - ray->step_x) * 0.5f) / ray->ray_dirx;
	else
		ray->prepwallwist = (ray->map_y - (player->y / 64.0f)
				+ (1 - ray->step_y) * 0.5f) / ray->ray_diry;
	crazy_diamond(ray);
	killer_queen(cube, ray, screenX, player);
}
