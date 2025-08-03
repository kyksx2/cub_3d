/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:04:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/03 20:14:22 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	print_error(char *str, int i)
{
	ft_printf("%s\n", str);
	exit(i);
}

int	bad_args(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i <= 4)
		return (1);
	if (ft_strncmp((av + i - 4), ".cub", 4) != 0)
		return (1);
		
	return (0);
}

void    init_data(t_data *cub, char *av)
{
    cub->file = ft_strdup(av);
    cub->height = 0;
    cub->mlx = NULL;
    cub->width = 0;
    cub->win = NULL;
    cub->x_file.color_c = 0;
    cub->x_file.color_f = 0;
    cub->x_file.text_ea = NULL;
    cub->x_file.text_no = NULL;
    cub->x_file.text_so = NULL;
    cub->x_file.text_we = NULL;
}

int main(int ac, char **av)
{
	t_data	cub;
	t_list	*read_map;

	if (ac < 2 || bad_args(av[1]))
		print_error("Error: bad argument.", 1);
	read_map = NULL;
	cub.file = av[1];
	read_map = read_line(&cub);
	cub.height = size_map(read_map);
	cub.x_file.map = convert_map(read_map);
	validate_map(&cub);
	// open_map(&cub);
	return (0);
}
