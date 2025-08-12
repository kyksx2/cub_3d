/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:45:43 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/12 15:16:33 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	start_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	return (line[i] == '1');
}

int	player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0');
}

int	sheinez2(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	print_map(t_data *cube)
{
	int	i;

	i = 0;
	while (cube->x_file.map[i])
	{
		printf("%s\n", cube->x_file.map[i]);
		i++;
	}
	return ;
}
