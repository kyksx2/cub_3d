/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:02:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/09 16:10:53 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void put_pixel(int x, int y, int color, t_data *game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;
    int index = y * game->main_img.line_len + x * game->main_img.bpp / 8;
    if (index < 0 || index + 2 >= (WIDTH * HEIGHT * (game->main_img.bpp / 8)))
        return;
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
				draw_square(x * 16, y * 16, 16, color, cube);
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

int get_pixel(t_texture *t, int x, int y)
{
    int idx = y * t->line_len + x * (t->bpp / 8);

    unsigned char r = t->data[idx];
    unsigned char g = t->data[idx + 1];
    unsigned char b = t->data[idx + 2];
    return r | (g << 8) | (b << 16);
}

void draw_line(t_player *player, t_data *cube, float start_x, int i)
{
    float rayon_x = cos(start_x);
    float rayon_y = sin(start_x);
    float px = player->x;
    float py = player->y;
    float prev_px = px;
    float prev_py = py;

    while(!touch(px, py, cube))
    {
        prev_px = px;
        prev_py = py;
        // if (DEBUG)
        // put_pixel(px, py, 0xFF0000, cube);
        px += rayon_x;
        py += rayon_y;
    }
    int map_x = floor(px / 64.0);
    int map_y = floor(py / 64.0);
    int prev_map_x = floor(prev_px / 64.0);
    int prev_map_y = floor(prev_py / 64.0);
    int side;
    if (map_x != prev_map_x && map_y != prev_map_y)
    {
        if (cube->x_file.map[prev_map_y][map_x] == '1')
            side = 1;
        else
            side = 0;
    }
    else if (map_x != prev_map_x)
        side = 0;
    else
        side = 1;

    int face;
    if (side == 0)
    {
        if (rayon_x > 0)
            face = WE;
        else
            face = EA;
    }
    else
    {
        if (rayon_y > 0)
            face = SO;
        else
            face = NO;
    }
    float wall;
    float cell_x = floor(px / 64.0) * 64.0;
    float cell_y = floor(py / 64.0) * 64.0;
    if (side == 0)
        wall = (py - cell_y) / 64.0;
    else
        wall = (px - cell_x) / 64.0;

    int tex_w = cube->texture[face].width;
    int tex_h = cube->texture[face].height;
    int tex = (int)(wall * (float)tex_w);
    if ((side == 0 && rayon_x > 0) || (side == 1 && rayon_y < 0))
        tex = tex_w - tex - 1;

    if (!DEBUG)
    {
        float dist = fixed_dist(px, py, cube);
        float height = (64 / dist) * (WIDTH / 2);
        int start_y = (HEIGHT - height) / 2;
        int end = start_y + height;

        float step = (float)tex_h / height;
        float tex_pos = (start_y - (HEIGHT / 2.0f) + (height / 2.0f)) * step;
        int y = 0;
        while(y < start_y)
        {
            put_pixel(i, y, 0x702963, cube);
            y++;
        }
        while (start_y < end)
        {
            int tex_y = (int)tex_pos;
            tex_pos += step;
            if (tex < 0)
                tex = 0;
            else if (tex >= tex_w)
                tex = tex_w - 1;
            if (tex_y < 0)
                tex_y = 0;
            else if (tex_y >= tex_h)
                tex_y = tex_h - 1;
            int color = get_pixel(&cube->texture[face], tex, tex_y);
            put_pixel(i, start_y, color, cube);
            start_y++;
        }
        while(end < HEIGHT)
        {
            put_pixel(i, end, 0x614051, cube);
            end++;
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
    while(i < WIDTH)
    {
        draw_line(player, cube, start_x, i);
        start_x += traction;
        i++;
    }
    // if (DEBUG)
    // {
    draw_square(player->x / 4, player->y / 4, 4, 0x00FF00, cube);
    draw_map(cube);
    // }
    mlx_put_image_to_window(cube->mlx, cube->win, cube->main_img.img, 0, 0);
    return (0);  
}
