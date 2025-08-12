/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:36:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 18:05:56 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calcul_dist_x(t_player *player, t_raycast *ray)
{
	float	player_map_x;

	player_map_x = player->x / 64.0f;
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player_map_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1 - player_map_x) * ray->deltaDistX;
	}
}

void	calcul_dist_y(t_player *player, t_raycast *ray)
{
	float	player_map_y;

	player_map_y = player->y / 64.0f;
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player_map_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1 - player_map_y) * ray->deltaDistY;
	}
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float px, float py, t_data *cube)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fixed;

	delta_x = px - cube->player.x;
	delta_y = py - cube->player.y;
	angle = atan2(delta_y, delta_x) - cube->player.angle;
	fixed = distance(delta_x, delta_y) * cos(angle);
	return (fixed);
}
