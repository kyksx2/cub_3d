/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:36:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 19:45:02 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calcul_dist_x(t_player *player, t_raycast *ray)
{
	float	player_map_x;

	player_map_x = player->x / 64.0f;
	if (ray->ray_dirx < 0)
	{
		ray->step_x = -1;
		ray->side_distx = (player_map_x - ray->map_x) * ray->delta_distx;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distx = (ray->map_x + 1 - player_map_x) * ray->delta_distx;
	}
}

void	calcul_dist_y(t_player *player, t_raycast *ray)
{
	float	player_map_y;

	player_map_y = player->y / 64.0f;
	if (ray->ray_diry < 0)
	{
		ray->step_y = -1;
		ray->side_disty = (player_map_y - ray->map_y) * ray->delta_disty;
	}
	else
	{
		ray->step_y = 1;
		ray->side_disty = (ray->map_y + 1 - player_map_y) * ray->delta_disty;
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
