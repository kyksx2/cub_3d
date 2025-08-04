/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:07:57 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/04 16:35:05 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void flood_fill_spaces(char **map, int i, int j, int rows)
{
	int cols;
	if (i < 0 || i >= rows)
		return;
	cols = ft_strlen(map[i]);
	if (j < 0 || j >= cols)
		return;
	if (map[i][j] != ' ')
		return;
	map[i][j] = '1';
	flood_fill_spaces(map, i + 1, j, rows);
	flood_fill_spaces(map, i - 1, j, rows);
	flood_fill_spaces(map, i, j + 1, rows);
	flood_fill_spaces(map, i, j - 1, rows);
}

static void fill_border_spaces(char **map)
{
	int rows = 0;
	while (map[rows])
		rows++;
	for (int i = 0; i < rows; i++)
	{
		int cols = ft_strlen(map[i]);
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
			{
				if (map[i][j] == ' ')
					flood_fill_spaces(map, i, j, rows);
			}
		}
	}
}

static int is_space(char **map)
{
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == ' ')
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

static int horizontal_walls(char **map, int last_line)
{
	int i;

	i = 0;
	while (map[0][i] && map[last_line][i])
	{
		if ((map[0][i] != '1' && map[0][i] != ' ')
			|| (map[last_line][i] != '1' && map[last_line][i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

static int vertical_walls(char **map)
{
	int i;
	int len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len == 0 || (map[i][0] != '1' && map[i][0] != ' ') 
			|| (map[i][len - 1] != '1' && map[i][len - 1] != ' '))
			return (0);
		i++;
	}
	return (1);
}

static void clean_newlines(char **map)
{
	int i;
	int len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
}

int	is_wall(t_data *data)
{
	int last;
	char **map;
	
	last = 0;
	map = data->x_file.map;
	while (map[last])
		last++;
	if (last < 3)
		return (0);
	clean_newlines(map);
	if (!horizontal_walls(map, last - 1))
		return (0);
	if (!vertical_walls(map))
		return (0);
	fill_border_spaces(map);
	if (is_space(map))
		return (0);
	return (1);
}
