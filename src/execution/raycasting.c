/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:39:15 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 17:55:58 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// playerDirX = cos(player->angle);
// playerDirY = sin(player->angle);
void	init_raycst(t_raycast *ray, t_fov *fov, t_player *player, float cameraX)
{
	ray->rayDirX = cos(player->angle) + fov->cameraPlaneX * cameraX;
	ray->rayDirY = sin(player->angle) + fov->cameraPlaneY * cameraX;
	ray->mapX = (int)player->x / 64.0f;
	ray->mapY = (int)player->y / 64.0f;
	ray->deltaDistX = fabs(1.0f / ray->rayDirX);
	ray->deltaDistY = fabs(1.0f / ray->rayDirY);
	ray->hit = 0;
}

void	dda_loop(t_raycast *ray, t_data *cube)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (ray->mapY >= 0 && ray->mapY < cube->height
			&& ray->mapX >= 0 && ray->mapX < cube->width
			&& cube->x_file.map[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
	}
}

void	crazy_diamond(t_raycast *ray)
{
	ray->height = (int)(HEIGHT / ray->prepWallDist);
	ray->drawStart = -ray->height / 2 + HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->height / 2 + HEIGHT / 2;
	if (ray->drawEnd >= HEIGHT)
		ray->drawEnd = HEIGHT - 1;
}

void	raycast(t_data *cube, float cameraX, int screenX)
{
	t_player	*player;
	t_fov		*fov;
	t_raycast	*ray;

	player = &cube->player;
	fov = &cube->fov_raycast;
	ray = &cube->raycasting;
	init_raycst(ray, fov, player, cameraX);
	calcul_dist_x(player, ray);
	calcul_dist_y(player, ray);
	dda_loop(ray, cube);
	if (ray->side == 0)
		ray->prepWallDist = (ray->mapX - (player->x / 64.0f) + (1 - ray->stepX)
				* 0.5f) / ray->rayDirX;
	else
		ray->prepWallDist = (ray->mapY - (player->y / 64.0f) + (1 - ray->stepY)
				* 0.5f) / ray->rayDirY;
	crazy_diamond(ray);
	killer_queen(cube, ray, screenX, player);
}
