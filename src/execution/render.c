/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:02:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 17:55:22 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_square(int size, int color, t_data *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = game->player.x / 4;
	y = game->player.y / 4;
	while (i < size)
		put_pixel(x + i++, y, color, game);
	i = 0;
	while (i < size)
		put_pixel(x, y + i++, color, game);
	i = 0;
	while (i < size)
		put_pixel(x + size, y + i++, color, game);
	i = 0;
	while (i < size)
		put_pixel(x + i++, y + size, color, game);
}

void	clear_image(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *cube)
{
	char	**map;
	int		color;
	int		x;
	int		y;

	y = 0;
	map = cube->x_file.map;
	color = 0xFFFFFF;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(16, color, cube);
			x++;
		}
		y++;
	}
}

int	touch(float px, float py, t_data *cube)
{
	int	x;
	int	y;

	x = px / 64;
	y = py / 64;
	if (y < 0 || y >= cube->height || x < 0 || x >= cube->width)
		return (1);
	if (cube->x_file.map[y][x] == '1')
		return (1);
	return (0);
}

int	execution(t_data *cube)
{
	int		screen_x;
	float	camera_x;

	screen_x = 0;
	mlx_clear_window(cube->mlx, cube->win);
	clear_image(cube);
	while (screen_x < WIDTH)
	{
		camera_x = 2.0f * screen_x / (float)WIDTH - 1.0f;
		raycast(cube, camera_x, screen_x);
		screen_x++;
	}
	draw_square(4, 0x00FF00, cube);
	draw_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->main_img.img, 0, 0);
	return (0);
}

// int	execution(t_data *cube)
// {
//     t_player *player;
//     player = &cube->player;
//     float traction = M_PI / 3 / WIDTH;
//     float start_x = player->angle - M_PI / 6;
//     int i = 0;

//     mlx_clear_window(cube->mlx, cube->win);
//     clear_image(cube);
//     while(i < WIDTH)
//     {
//         draw_line(player, cube, start_x, i);
//         start_x += traction;
//         i++;
//     }
//     draw_square(player->x / 4, player->y / 4, 4, 0x00FF00, cube);
//     draw_map(cube);
//     mlx_put_image_to_window(cube->mlx, cube->win, cube->main_img.img, 0, 0);
//     return (0);  
// }

// void draw_line(t_player *player, t_data *cube, float start_x, int i)
// {
//     float px = player->x;
//     float py = player->y;
//     float prev_px = px;
//     float prev_py = py;

//     while(!touch(px, py, cube))
//     {
//         prev_px = px;
//         prev_py = py;
//         px += cos(start_x) * 0.05f;
//         py += sin(start_x) * 0.05f;
//     }
//     int map_x = floor(px / 64.0);
//     int map_y = floor(py / 64.0);
//     int prev_map_x = floor(prev_px / 64.0);
//     int prev_map_y = floor(prev_py / 64.0);
//     int side;
//     if (map_x != prev_map_x && map_y != prev_map_y)
//     {
//         if (cube->x_file.map[prev_map_y][map_x] == '1')
//             side = 1;
//         else
//             side = 0;
//     }
//     else if (map_x != prev_map_x)
//         side = 0;
//     else
//         side = 1;
//     int face;
//     if (side == 0)
//     {
//         if (cos(start_x) > 0)
//             face = WE;
//         else
//             face = EA;
//     }
//     else
//     {
//         if (sin(start_x) > 0)
//             face = SO;
//         else
//             face = NO;
//     }
//     float wall;
//     float cell_x = floor(px / 64.0) * 64.0;
//     float cell_y = floor(py / 64.0) * 64.0;
//     if (side == 0)
//         wall = (py - cell_y) / 64.0;
//     else
//         wall = (px - cell_x) / 64.0;
//     int tex_w = cube->texture[face].width;
//     int tex_h = cube->texture[face].height;
//     int tex = (int)(wall * (float)tex_w);
//     if ((side == 0 && cos(start_x) > 0) || (side == 1 && sin(start_x) < 0))
//         tex = tex_w - tex - 1;

//     float dist = fixed_dist(px, py, cube);
//     float height = (64.0 / dist) * HEIGHT;//(WIDTH / 2);
//     int start_y = (HEIGHT - height) / 2;
//     int end = start_y + height;
//     float step = (float)tex_h / height;
//     float tex_pos = (start_y - (HEIGHT / 2.0f) + (height / 2.0f)) * step;
//     int y = 0;
//     while(y < start_y)
//     {
//         put_pixel(i, y, 0x702963, cube);
//         y++;
//     }
//     while (start_y < end)
//     {
//         int tex_y = (int)tex_pos;
//         tex_pos += step;
//         if (tex < 0)
//             tex = 0;
//         else if (tex >= tex_w)
//             tex = tex_w - 1;
//         if (tex_y < 0)
//             tex_y = 0;
//         else if (tex_y >= tex_h)
//             tex_y = tex_h - 1;
//         int color = get_pixel(&cube->texture[face], tex, tex_y);
//         put_pixel(i, start_y, color, cube);
//         start_y++;
//     }
//     while(end < HEIGHT)
//     {
//         put_pixel(i, end, 0x614051, cube);
//         end++;
//     }
// }
