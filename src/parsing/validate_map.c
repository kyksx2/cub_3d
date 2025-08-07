/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:19:20 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/07 14:59:46 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void get_max(char **map, t_data *size)
{
	int i;
	int len;
	int max_width;
	
	max_width = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	size->height = i;
	size->width = max_width; 
}


char	*size_width(char *line, int max)
{
	int 	i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (max + 1));
	if (!new)
		print_error(NULL, "allocation.", -1);
	while (line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (i < max)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	regular_lines(t_data *data)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (data->height + 1));
	if (!new_map)
		print_error(NULL, "allocation.", -1);
	while (data->x_file.map[i])
	{
		new_map[i] = size_width(data->x_file.map[i], data->width);
		free(data->x_file.map[i]);
		i++;
	}
	new_map[i] = NULL;
	free(data->x_file.map);
	data->x_file.map = new_map;
}

void	fill_space(t_data *data)
{
	int	i;;
	int	j;

	i = 0;
	while (data->x_file.map[i])
	{
		j = 0;
		while (data->x_file.map[i][j])
		{
			if (data->x_file.map[i][j] == ' ')
				data->x_file.map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	final_map(t_data *game)
{
	get_max(game->x_file.map, game);
	regular_lines(game);
	fill_space(game);
}
