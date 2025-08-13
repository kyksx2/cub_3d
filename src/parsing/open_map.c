/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:00:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/13 15:07:16 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	miss_line(t_data *cube)
{
	if (!cube->x_file.text_no)
		return (1);
	if (!cube->x_file.text_so)
		return (1);
	if (!cube->x_file.text_we)
		return (1);
	if (!cube->x_file.text_ea)
		return (1);
	if (!cube->x_file.color_c)
		return (1);
	if (!cube->x_file.color_f)
		return (1);
	else
		return (0);
}

void	open_map(t_data *cube)
{
	char	*str;
	int		fd;

	jojo_bizzare_aventure(cube);
	fd = open(cube->file, O_RDONLY);
	if (fd < 0)
		print_error(cube, "fd ouvert.", EXIT_FAILURE);
	str = get_next_line(fd);
	while (str)
	{
		if (start_map(str))
		{
			read_line(cube, fd, str);
			break ;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (!str)
		print_error(cube, "map introuvable.", 1);
	if (miss_line(cube))
		print_error(cube, "il manque un element.", 1);
	final_map(cube);
}
