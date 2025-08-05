/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:34:21 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/05 19:18:27 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void err_free(t_data *err)
{
	int i;

	if (!err || !err->x_file.map)
		return;
	i = 0;
	while (err->x_file.map[i])
	{
		free(err->x_file.map[i]);
		err->x_file.map[i] = NULL;
		i++;
	}
	free(err->x_file.map);
	err->x_file.map = NULL;
}

void    print_error(t_data *data, char *str, int i)
{
    err_free(data);
    ft_printf("Erreur: %s\n", str);
    exit(i);
}

void	map_error(t_list *error, char **map, int i)
{
	while (i > 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_lstclear(&error, free);
	ft_printf("Erreur : echec de l'allocation de la map.\n");
	exit(EXIT_FAILURE);
}
