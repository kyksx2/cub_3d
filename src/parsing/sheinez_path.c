/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sheinez_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:55:02 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/15 14:55:46 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid(char c)
{
	return (c == '1' || c == '\n');
}

int	is_tex(char *str, int i)
{
	if ((str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		|| (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		|| (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		|| (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' '))
		return (1);
	return (0);
}

int	is_color(char *str, int i)
{
	if ((str[i] == 'F' && str[i + 1] == ' ')
		|| (str[i] == 'C' && str[i + 1] == ' '))
		return (1);
	return (0);
}
