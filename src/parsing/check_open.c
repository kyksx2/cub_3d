/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:37:25 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/13 15:06:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_xpm(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return ((!ft_strcmp(str + len - 4, ".xpm")));
}

int	check_open(char *str)
{
	int	fd;

	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
