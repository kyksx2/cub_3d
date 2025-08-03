/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:07:57 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/03 20:04:39 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int horizontal_walls(char **map, int last_line)
{
	int	i;

	i = 0;
	while (map[0][i] && map[last_line][i])
	{
		if ((map[0][i] != '1' && map[0][i] != ' ') || (map[last_line][i] != '1'
			&& map[last_line][i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

static int	vertical_walls(char **map)
{
	int	i;
	int	len;
	
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

static void	clean_newlines(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
}

int	is_wall(t_data *wall)
{
	int	last;

	last = 0;
	while (wall->x_file.map[last])
		last++;
	if (last < 3)
		return (0);
	last--;
	clean_newlines(wall->x_file.map);
	if (!horizontal_walls(wall->x_file.map, last))
		print_error("Error: lines invalid.", 0);
	if (!vertical_walls(wall->x_file.map))
		print_error("Error: Columns invalid.", 0);
	return (1);
}
