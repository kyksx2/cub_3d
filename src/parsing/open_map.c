/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:00:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/02 19:11:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_file(t_data *cube, char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if(str[i] == 'N' && str[i + 1] == 'O')
		
}

void	open_map(t_data *cube, char *av)
{
	char	*tmp;
	char	*str;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		print_error("Error: open fd.", EXIT_FAILURE);
	str = get_next_line(fd);
	while (str)
	{
		check_file(cube, str);
		str = get_next_line(fd);
	}
}
