/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:04:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/03 13:50:45 by kjolly           ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_data	cub;
	if (ac < 2 || bad_args(av[1]))
		print_error("Error: bad argument.", 1);
	cub.file = av[1];
	open_map(&cub);
	return (0);
}
