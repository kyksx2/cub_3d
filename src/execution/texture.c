/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:48:36 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 21:24:56 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_pixel(t_texture *t, int x, int y)
{
	int				idx;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	idx = y * t->line_len + x * (t->bpp / 8);
	r = t->data[idx];
	g = t->data[idx + 1];
	b = t->data[idx + 2];
	return (r | (g << 8) | (b << 16));
}

void	put_pixel(int x, int y, int color, t_data *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->main_img.line_len + x * game->main_img.bpp / 8;
	if (index < 0 || index + 2 >= (WIDTH * HEIGHT * (game->main_img.bpp / 8)))
		return ;
	game->main_img.data[index] = color & 0xFF;
	game->main_img.data[index + 1] = (color >> 8) & 0xFF;
	game->main_img.data[index + 2] = (color >> 16) & 0xFF;
}

int	find_face(t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dirx > 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (ray->ray_diry > 0)
			return (SO);
		else
			return (NO);
	}
}

void	killer_queen(t_data *cube, t_raycast *ray, int sX, t_player *player)
{
	float	wall_x;
	int		face;
	int		tex_x;
	int		tex_y;
	float	step;
	float	tex_pos;
	int		color;
	int		start_y;
	int		end_y;
	int		y;

	start_y = (HEIGHT - ray->height) / 2;
	end_y = start_y + ray->height;
	y = 0;
	if (ray->side == 0)
		wall_x = (player->y / 64.0f) + ray->prepwallwist * ray->ray_diry;
	else
		wall_x = (player->x / 64.0f) + ray->prepwallwist * ray->ray_dirx;
	wall_x -= floor(wall_x);
	face = find_face(ray);
	tex_x = (int)(wall_x * (float)(cube->texture[face].width));
	if ((ray->side == 0 && ray->ray_dirx > 0)
		|| (ray->side == 1 && ray->ray_diry < 0))
			tex_x = cube->texture[face].width - tex_x - 1;
	step = (float)cube->texture[face].height / ray->height;
	tex_pos = (start_y - (HEIGHT / 2) + (ray->height / 2)) * (int)step;
	y = 0;
	while (y < start_y)
	{
		put_pixel(sX, y, 0x702963, cube);
		y++;
	}
	y = start_y;
	while (y < end_y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= cube->texture[face].height)
			tex_y = cube->texture[face].height - 1;
		tex_pos += step;
		color = get_pixel(&cube->texture[face], tex_x, tex_y);
		put_pixel(sX, y, color, cube);
		y++;
	}
	while (y < HEIGHT)
	{
		put_pixel(sX, y, 0x614051, cube);
		y++;
	}
}

// void    killer_queen(t_data *cube, t_raycast *ray, int screenX, t_player *player)
// {
//     float   wall_x; // coordonee d'impact 0 ou 1;
//     int     face;
//     int     step;
//     int     texX;
//     int     texY;
//     int     texPos;
//     int     color;
//     int     y = 0;
//     if (ray->side == 0)
//         wall_x = (player->y / 64.0f) + ray->prepwallwist * ray->ray_diry;
//     else
//         wall_x = (player->x / 64.0f) + ray->prepwallwist * ray->ray_dirx;
//     wall_x -= floor(wall_x); // ? garder la partie decimale
//     face = find_face(ray);
//     texX = (int)(wall_x * (float)(cube->texture[face].width));
//     if ((ray->side == 0 && ray->ray_dirx > 0)
//         || (ray->side == 1 && ray->ray_diry < 0))
//         texX = cube->texture[face].width - texX - 1;
//     step = (float)cube->texture[face].height / ray->height;
//     texPos = (ray->drawStart - HEIGHT / 2 + ray->height / 2) * step;
//     int start_y = (HEIGHT - ray->height) / 2;
//     int end = start_y + ray->height;
//     while(y < start_y)
//     {
//         put_pixel(screenX, y, 0x702963, cube);
//         y++;
//     }
//     while (start_y < ray->drawEnd)
//     {
//         texY = (int)texPos & (cube->texture[face].height - 1);
//         texPos += step;
//         color = get_pixel(&cube->texture[face], texX, texY);
//         put_pixel(screenX, y, color, cube);
//         start_y++;
//     }
//     while(end < HEIGHT)
//     {
//         put_pixel(screenX, ray->drawEnd, 0x614051, cube);
//         end++;
//     }
// }
