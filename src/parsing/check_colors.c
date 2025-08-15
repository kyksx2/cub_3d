/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:47:29 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/15 16:07:56 by kjolly           ###   ########.fr       */
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

int	set_final_value(int type, t_data *cube, int final_value)
{
	if (type == F)
	{
		if (cube->x_file.color_f != 0)
			return (printf("Erreur: couleur du sol déjà définie.\n"), 0);
		cube->x_file.color_f = final_value;
	}
	else if (type == C)
	{
		if (cube->x_file.color_c != 0)
			return (printf("Erreur: couleur du plafond déjà définie.\n"), 0);
		cube->x_file.color_c = final_value;
	}
	return (1);
}

int	check_color(t_data *cube, char *str, int type)
{
	int	i;
	int	k;
	int	value[3];
	int	final_value;

	i = 0;
	k = 0;
	while (i < 3)
		value[i++] = 0;
	i = 0;
	while (k < 3)
	{
		if (!color_loop(str, &i, k, value))
			return (printf("Erreur: mauvais code RGB.\n"), 0);
		k++;
	}
	final_value = (value[0] << 16) | (value[1] << 8) | value[2];
	if (!set_final_value(type, cube, final_value))
		return (0);
	return (1);
}

// int	check_color(t_data *cube, char *str, int type)
// {
// 	int	i;
// 	int	k;
// 	int	value[3];
// 	int	final_value;

// 	i = ((final_value = 0));
// 	k = 0;
// 	while (i < 3)
// 		value[i++] = 0;
// 	i = 0;
// 	while (k < 3)
// 	{
// 		if (!color_loop(str, &i, k, value))
// 		{
// 			printf("mauvais code rgb.\n");
// 			return (0);
// 		}
// 		k++;
// 	}
// 	final_value = (value[0] << 16) | (value[1] << 8) | value[2];
// 	if (type == F && !cube->x_file.color_f)
// 		cube->x_file.color_f = final_value;
// 	else if (type == C && !cube->x_file.color_c)
// 		cube->x_file.color_c = final_value;
// 	return (1);
// }
