/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:02:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/07 16:58:48 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void put_pixel(int x, int y, int color, t_data *game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;
    int index = y * game->texture.line_len + x * game->texture.bpp / 8;
    game->texture.data[index] = color & 0xFF;
    game->texture.data[index + 1] = (color >> 8) & 0xFF;
    game->texture.data[index + 2] = (color >> 16) & 0xFF;
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

int	execution(t_data *cube)
{
    t_player *player = &cube->player;

    mlx_clear_window(cube->mlx, cube->win);
    clear_image(cube);
    draw_square(player->x, player->y, 10, 0x00FF00, cube);
	draw_map(cube);
    mlx_put_image_to_window(cube->mlx, cube->win, cube->texture.img, 0, 0);
    return (0);  
}
