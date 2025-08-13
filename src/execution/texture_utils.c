/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:13:51 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/13 11:48:24 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ok_garmin_initialise_la_structure(t_garmin	*tex, t_raycast *ray)
{
	tex->color = 0;
	tex->face = find_face(ray);
	tex->start_y = (HEIGHT - ray->height) / 2;
	tex->end_y = tex->start_y + ray->height;
	tex->step = 0.0f;
	tex->tex_pos = 0.0f;
	tex->tex_x = 0;
	tex->tex_y = 0;
	tex->wall_x = 0.0f;
	tex->y = 0;
}

void	floor_ceiling_looping(t_garmin *tex, t_data *cube, int sX)
{
	while (tex->y < tex->start_y)
	{
		put_pixel(sX, tex->y, cube->x_file.color_c, cube);
		tex->y++;
	}
	tex->y = tex->start_y;
	while (tex->y < tex->end_y)
	{
		tex->tex_y = (int)tex->tex_pos;
		if (tex->tex_y < 0)
			tex->tex_y = 0;
		else if (tex->tex_y >= cube->texture[tex->face].height)
			tex->tex_y = cube->texture[tex->face].height - 1;
		tex->tex_pos += tex->step;
		tex->color = get_pixel(&cube->texture[tex->face],
				tex->tex_x, tex->tex_y);
		put_pixel(sX, tex->y, tex->color, cube);
		tex->y++;
	}
	while (tex->y < HEIGHT)
	{
		put_pixel(sX, tex->y, cube->x_file.color_f, cube);
		tex->y++;
	}
}
