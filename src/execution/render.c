/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:02:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/06 17:07:21 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	execution(t_data *cube)
{
	int	i, j;
	int	x, y;
	int	color;

	i = 0;
	while (cube->x_file.map[i])
	{
		j = 0;
		while (cube->x_file.map[i][j])
		{
			if (cube->x_file.map[i][j] == '1')
				color = 0xFF0000;
			else 
				color = 0xFFFF00;

			y = 0;
			while (y < 64)
			{
				x = 0;
				while (x < 64)
				{
					mlx_pixel_put(cube->mlx, cube->win, j * 64 + x, i * 64 + y, color);
					x++;
				}
				y++;
			}
			j++;
		}
		i++;
	}
    int px = (int)cube->player.x;
    int py = (int)cube->player.y;

    int start_x = px - 10 / 2;
    int start_y = py - 10 / 2;

    for (y = 0; y < 10; y++)
    {
        for (x = 0; x < 10; x++)
        {
            mlx_pixel_put(cube->mlx, cube->win, start_x + x, start_y + y, 0xFFFFFF);
        }
    }	return (0);
}
