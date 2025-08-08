/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:04:45 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/08 14:03:31 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_pos(t_data *init, char c)
{
	if (c == 'N')
	{
		init->type = NORTH;
		init->count_player++;
	}
	if (c == 'S')
	{
		init->type = SOUTH;
		init->count_player++;
	}
	if (c == 'E')
	{
		init->type = EAST;
		init->count_player++;
	}
	if (c == 'W')
	{
		init->type = WEST;
		init->count_player++;
	}
}

int	check_elements(t_data *elem)
{
	int	i;
	int	j;

	i = 0;
	while (elem->x_file.map[i])
	{
		j = 0;
		while (elem->x_file.map[i][j])
		{
			if (sheinez2(elem->x_file.map[i][j]))
				init_pos(elem, elem->x_file.map[i][j]);
			else if (elem->x_file.map[i][j] != '0'
				&& elem->x_file.map[i][j] != '1'
				&& elem->x_file.map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	if (elem->count_player > 1)
		print_error(elem, "plus d'un joueur.", -1);
	else if (elem->count_player == 0)
		print_error(elem, "aucun joueur detecte.", -1);
	return (1);
}

int	validate_map(t_data *verif)
{
	if (!is_wall(verif))
		print_error(verif, "murs invalides.", -1);
	if (!check_elements(verif))
		print_error(verif, "éléments invalides.", -1);
	ft_printf("Success.\n");
	return (0);
}
