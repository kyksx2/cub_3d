/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:45:43 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/03 19:45:46 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	ft_strcspn(char *str, char reject)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == reject)
			break ;
		i++;
	}
	return (i);
}

