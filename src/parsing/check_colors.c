/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:47:29 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/14 14:53:15 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	color_loop(char *str, int *i, int k, int *value)
{
	while (str[*i] == ' ')
		(*i)++;
	while (ft_isdigit(str[*i]))
		value[k] = value[k] * 10 + (str[(*i)++] - '0');
	if (value[k] < 0 || value[k] > 255)
		return (0);
	while (str[*i] == ' ')
		(*i)++;
	if (k == 2 && str[*i] != '\n')
		return (0);
	if (k < 2)
	{
		if (str[*i] != ',')
			return (0);
		(*i)++;
	}
	return (1);
}

int	check_color(t_data *cube, char *str, int type)
{
	int	i;
	int	k;
	int	value[3];
	int	final_value;

	i = ((final_value = 0));
	k = 0;
	while (i < 3)
		value[i++] = 0;
	i = 0;
	while (k < 3)
	{
		if (!color_loop(str, &i, k, value))
		{
			printf("mauvais code rgb.\n");
			return (0);
		}
		k++;
	}
	final_value = (value[0] << 16) | (value[1] << 8) | value[2];
	if (type == F && !cube->x_file.color_f)
		cube->x_file.color_f = final_value;
	else if (type == C && !cube->x_file.color_c)
		cube->x_file.color_c = final_value;
	return (1);
}
