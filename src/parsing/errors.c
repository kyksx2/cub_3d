/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:34:21 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/06 12:10:18 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void free_map(t_data *err)
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
	free_cube(data);
    ft_printf("Erreur: %s\n", str);
    exit(i);
}

void	map_error(t_list *error, char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_lstclear(&error, free);
	ft_printf("Erreur : echec de l'allocation de la map.\n");
}

void	free_cube(t_data *cube)
{
	if(cube->x_file.text_no)
		free(cube->x_file.text_no);
	if(cube->x_file.text_so)
		free(cube->x_file.text_so);
	if(cube->x_file.text_we)
		free(cube->x_file.text_we);
	if(cube->x_file.text_ea)
		free(cube->x_file.text_ea);
	if(cube->x_file.map)
		free_map(cube);
	if (cube->file)
		free(cube->file);
}
