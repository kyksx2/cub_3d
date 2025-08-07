/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:33:19 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/07 17:24:39 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	map_error(t_list *error, char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_lstclear(&error, free);
	ft_printf("Erreur : echec de l'allocation de la map.\n");
}

int	is_map_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' '
			&& str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

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

void read_line(t_data *cube, int fd, char *first_map_line)
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
	//free(line)
    validate_map(cube);
}

char	**convert_map(t_data *cube, t_list *map_lines)
{
	t_list	*tmp;
	char	**map;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = size_map(map_lines);
	tmp = map_lines;
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	while (tmp)
	{
		j = 0;
		map[i] = ft_strdup(tmp->content);
		if (!map[i])
		{
			map_error(map_lines, map, i);
			exit(-1);
		}
		while (map[i][j] && map[i][j] != '1')
			j++;
		if (map[i][j] == '1')
		{
			if (!is_map_valid(map[i]))
			{
				map_error(map_lines, map, i);
				print_error(cube, "caractere invalide.", -1);
			}
		}
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(&map_lines, free);
	return (map);
}
