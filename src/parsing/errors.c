/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:34:21 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/09 14:58:23 by kjolly           ###   ########.fr       */
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

void	free_x_file(t_file *file)
{
	int i;

	i = 0;
	if (file->text_no)
		free(file->text_no);
	if (file->text_so)
		free(file->text_so);
	if (file->text_ea)
		free(file->text_ea);
	if (file->text_we)
		free(file->text_we);
	if (file->map)
	{
		while(file->map[i])
		{
			free(file->map[i]);
			i++;
		}
		free(file->map);
	}
		
}

void	free_img(t_data *cube, t_texture *texture)
{
	if (texture[0].img)
		mlx_destroy_image(cube->mlx, texture[0].img);
	if (texture[1].img)
		mlx_destroy_image(cube->mlx, texture[1].img);
	if (texture[2].img)
		mlx_destroy_image(cube->mlx, texture[2].img);
	if (texture[3].img)
		mlx_destroy_image(cube->mlx, texture[3].img);	
}

void	free_cube(t_data *cube)
{
	if (!cube)
		return ;
	free_x_file(&cube->x_file);
	free_img(cube, cube->texture);
	if (cube->main_img.img)
		mlx_destroy_image(cube->mlx, cube->main_img.img);
	if (cube->win && cube->mlx)
		mlx_destroy_window(cube->mlx, cube->win);
	if (cube->mlx)
	{
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
	}
}

void    print_error(t_data *data, char *str, int i)
{
	free_cube(data);
    ft_printf("Erreur: %s\n", str);
    exit(i);
}
