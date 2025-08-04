/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:04:45 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/04 11:18:41 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// int	check_all(t_data *all, t_list *map, char *str)
// {
	
// }

int	validate_map(t_data *verif)
{
	int	i;
	int	j;
	
	i = 0;
	while (verif->x_file.map[i])
	{
		j = 0;
		while (verif->x_file.map[i][j])
		{
			if (is_map_valid(verif->x_file.map[i]))
			{
				if (verif->x_file.map[i][j] == '1')
					is_wall(verif);
			}
			else
				print_error("map invalide.", -1);
			j++;
		}
		i++;
	}
	return (ft_printf("Success.\n"), 0);
}
