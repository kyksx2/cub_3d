/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:45:43 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/12 21:29:07 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	load_img(t_data *cube, t_texture *texture, char *str)
{
	texture->img = mlx_xpm_file_to_image(cube->mlx, str, &texture->width,
			&texture->height);
	if (!texture->img)
		print_error(cube, "chargement de l'image.", -1);
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->data)
		print_error(cube, "chargement de l'image.", -1);
}

int	start_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	return (line[i] == '1');
}

int	player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0');
}

int	sheinez2(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	print_map(t_data *cube)
{
	int	i;

	i = 0;
	while (cube->x_file.map[i])
	{
		printf("%s\n", cube->x_file.map[i]);
		i++;
	}
	return ;
}
