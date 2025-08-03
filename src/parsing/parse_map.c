/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:33:19 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/03 16:17:22 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	map_error(t_list *error, char **map, int i)
{
	while (i > 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_lstclear(&error, free);
	print_error("Error: malloc of map failed.", -1);
}

int	is_map_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
		&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	size_map(t_list *map_lines)
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

t_list	*read_line(t_data *check)
{
	t_list	*map_lines;
	char	*line;
	int		fd;

	map_lines = NULL;
	fd = open(check->file, O_RDONLY);
	if (fd < 0)
		print_error("Error: file can't open.", -1);
	while ((line = get_next_line(fd)))
	{
		if (!is_map_valid(line))
		{
			free(line);
			ft_lstclear(&map_lines, free);
			close(fd);
			print_error("Error: invalid character in map.", -1);
		}
		ft_lstadd_back(&map_lines, ft_lstnew(line));
	}
	close(fd);
	return (map_lines);
}

char	**convert_map(t_data *check, t_list *map_lines)
{
	t_list	*tmp;
	char	**map;
	int		len;
	int		i;
	
	i = 0;
	len = size_map(map_lines);
	tmp = map_lines;
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		if (!map[i])
			map_error(map_lines, map, i);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(&map_lines, free);
	return (map);
}
