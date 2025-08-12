/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:37:25 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/12 13:12:11 by kjolly           ###   ########.fr       */
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

// int	check_open(char *str)
// {
// 	int		fd;

// 	printf("check_open : '%s'\n", str); // guillemets pour voir les bords
// 	for (int i = 0; str[i]; i++)
// 		printf("char[%d] = %d\n", i, (unsigned char)str[i]);
// 	fd = open(str, O_RDONLY);
// 	if (fd < 0)
// 		perror("open failed"); // pour voir la vraie raison
// 	else
// 		close(fd);
// 	return (fd >= 0);
// }

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
