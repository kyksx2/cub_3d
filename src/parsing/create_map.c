/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:33:19 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/12 15:59:15 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	size_map(t_list *map_lines)
{
	t_list	*convert;
	int		height;

	convert = map_lines;
	height = 0;
	while (convert)
	{
		height++;
		convert = convert->next;
	}
	return (height);
}

void	read_line(t_data *cube, int fd, char *first_map_line)
{
	t_list	*map_lines;
	char	*line;

	map_lines = NULL;
	ft_lstadd_back(&map_lines, ft_lstnew(first_map_line));
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&map_lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	cube->height = size_map(map_lines);
	cube->x_file.map = convert_map(cube, map_lines);
	validate_map(cube);
}

static void	valid_map(t_data *cube, t_list *map_lines, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] && map[i][j] != '1')
		j++;
	if (map[i][j] == '1' && !is_map_valid(map[i]))
	{
		map_error(map_lines, map, i);
		print_error(cube, "caractere invalide.", -1);
	}
}

static void	copy_map(t_list *map_lines, char **map, int i, char *content)
{
	map[i] = ft_strdup(content);
	if (!map[i])
	{
		map_error(map_lines, map, i);
		exit(-1);
	}
}

char	**convert_map(t_data *cube, t_list *map_lines)
{
	t_list	*tmp;
	char	**map;
	int		len;
	int		i;

	len = size_map(map_lines);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	tmp = map_lines;
	i = 0;
	while (tmp)
	{
		copy_map(map_lines, map, i, tmp->content);
		valid_map(cube, map_lines, map, i);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(&map_lines, free);
	return (map);
}
