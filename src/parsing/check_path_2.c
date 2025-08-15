/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:17 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/15 14:20:35 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	dup_path_2(int type, t_data *cube, char **trimmed)
{
	if (type == WE)
	{
		if (cube->x_file.text_we)
		{
			printf("Erreur: texture ouest en double.\n");
			return (free(*trimmed), 0);
		}
		cube->x_file.text_we = ft_strdup(*trimmed);
		return (free(*trimmed), 1);
	}
	else if (type == EA)
	{
		if (cube->x_file.text_ea)
		{
			printf("Erreur: texture est en double.\n");
			return (free(*trimmed), 0);
		}
		cube->x_file.text_ea = ft_strdup(*trimmed);
		return (free(*trimmed), 1);
	}
	return (1);
}

int	dup_path_1(int type, t_data *cube, char **trimmed)
{
	if (type == NO)
	{
		if (cube->x_file.text_no)
		{
			printf("Erreur: texture nord en double.\n");
			return (free(*trimmed), 0);
		}
		cube->x_file.text_no = ft_strdup(*trimmed);
		return (free(*trimmed), 1);
	}
	else if (type == SO)
	{
		if (cube->x_file.text_so)
		{
			printf("Erreur: texture sud en double.\n");
			return (free(*trimmed), 0);
		}
		cube->x_file.text_so = ft_strdup(*trimmed);
		return (free(*trimmed), 1);
	}
	return (1);
}

int	check_color_line(char *str, int i, t_data *cube)
{
	if (str[i] == 'F' && str[i + 1] == ' ')
	{
		if (!check_color(cube, str + i + 2, F))
			return (0);
	}
	else if (str[i] == 'C' && str[i + 1] == ' ')
	{
		if (!check_color(cube, str + i + 2, C))
			return (0);
	}
	return (1);
}
