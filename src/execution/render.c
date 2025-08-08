/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:02:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/08 15:25:11 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void put_pixel(int x, int y, int color, t_data *game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;
    int index = y * game->main_img.line_len + x * game->main_img.bpp / 8;
    game->main_img.data[index] = color & 0xFF;
    game->main_img.data[index + 1] = (color >> 8) & 0xFF;
    game->main_img.data[index + 2] = (color >> 16) & 0xFF;
}

void draw_square(int x, int y, int size, int color, t_data *game)
{
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y, color, game);
    for(int i = 0; i < size; i++)
        put_pixel(x, y + i, color, game);
    for(int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, game);
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, game);
}   

void clear_image(t_data *game)
{
    int y;
    int x;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            put_pixel(x, y, 0, game);
            x++;
        }
        y++;
    }
}

void draw_map(t_data *cube)
{
	char **map = cube->x_file.map;
	int	color = 0x0000FF;
	int x;
	int y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * 64, y * 64, 64, color, cube);
			x++;
		}
		y++;
	}
	
}

int touch(float px, float py, t_data *cube)
{
    int x;
    int y;

    x = px / 64;
    y = py / 64;
    if (y < 0 || y >= cube->height || x < 0 || x >= cube->width)
        return (1);
    if (cube->x_file.map[y][x] == '1')
        return (1);
    return (0);
}

float distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float fixed_dist(float px, float py, t_data *cube)
{
    float delta_x = px - cube->player.x;
    float delta_y = py - cube->player.y;
    float angle = atan2(delta_y, delta_x) - cube->player.angle;
    float fixed = distance(delta_x, delta_y) * cos(angle);
    return (fixed);
}

void draw_line(t_player *player, t_data *cube, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float px = player->x;
    float py = player->y;

    while(!touch(px, py, cube))
    {
        if (DEBUG)
            put_pixel(px, py, 0xFF0000, cube);
        px += cos_angle;
        py += sin_angle;
    }
    if (!DEBUG)
    {
        float dist = fixed_dist(px, py, cube);
        float height = (64 / dist) * (WIDTH / 2);
        int start_y = (HEIGHT - height) / 2;
        int end = start_y + height;
        while (start_y < end)
        {
            put_pixel(i, start_y, 0xFFFFFF, cube);
            start_y++;
        }        
    }
}

int	execution(t_data *cube)
{
    t_player *player;
    player = &cube->player;
    float traction = M_PI / 3 / WIDTH;
    float start_x = player->angle - M_PI / 6;
    int i = 0;

    mlx_clear_window(cube->mlx, cube->win);
    clear_image(cube);
    if (DEBUG)
    {
        draw_square(player->x, player->y, 10, 0x00FF00, cube);
        draw_map(cube);
    }
    while(i < WIDTH)
    {
        draw_line(player, cube, start_x, i);
        start_x += traction;
        i++;
    }
    mlx_put_image_to_window(cube->mlx, cube->win, cube->main_img.img, 0, 0);
    return (0);  
}
