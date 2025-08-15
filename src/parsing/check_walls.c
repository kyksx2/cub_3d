/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:07:57 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/15 14:30:08 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	horizontal_walls(char **map)
{
	int	i;
	int	len;

	if (!*map || !map)
		return (0);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		while (len > 0 && map[i][len - 1] == ' ')
			len--;
		if (len == 0)
			return (0);
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (0);
		if (map[i][len - 1] != '1')
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

int	check_space(char **map, int i, int j)
{
	if (i <= 0 || j <= 0 || !map[i + 1] || !map[i][j + 1])
		return (1);
	if (!map[i - 1][j] || !map[i + 1][j] || !map[i][j - 1] || !map[i][j + 1])
		return (1);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
		map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (1);
	return (0);
}

int	bad_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (player(map[i][j]))
			{
				if (check_space(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_wall(t_data *data)
{
	int		last;
	char	**map;

	last = 0;
	map = data->x_file.map;
	while (map[last])
		last++;
	if (last < 3)
		return (0);
	clean_newlines(map);
	if (!horizontal_walls(map))
		return (0);
	if (bad_map(map))
		print_error(data, "map invalide.", -1);
	return (1);
}
