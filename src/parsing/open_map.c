/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:00:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/03 16:16:41 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_xpm(char *str)
{
	int	len;

	len = ft_strlen(str) - 4;
	if (len < 4)
		return (0);
	if (!ft_strncmp(str + len, ".xpm", 4))
		return (0);
	return (1);
}

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

void	check_path(t_data *cube, char *str, int type)
{
	int	i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if (!check_xpm(str))
		print_error("Error: texture path need \".xpm\"", 1);
	if (!check_open(str))
		print_error("Error: texture path invalid", 1);
	if (type = NO && !cube->x_file.text_no)
		cube->x_file.text_no = ft_strdup(str);
	else if (type = SO && !cube->x_file.text_so)
		cube->x_file.text_no = ft_strdup(str);
	else if (type = WE && !cube->x_file.text_we)
		cube->x_file.text_no = ft_strdup(str);
	else if (type = EA && !cube->x_file.text_ea)
		cube->x_file.text_no = ft_strdup(str);
}

void	check_color(t_data *cube, char *str, int type)
{

}

void	check_line(t_data *cube, char *str)
{
	int	i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if(str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		check_path(cube, &str[i + 3], NO);
	else if(str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		check_path(cube, &str[i + 3], SO);
	else if(str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		check_path(cube, &str[i + 3], WE);
	else if(str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		check_path(cube, &str[i + 3], EA);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		check_color(cube, &str[i + 2], F);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		check_color(cube, &str[i + 2], C);
	else if (str[i] == '1')
		return ;
	else if (str[i] == "\n")
		return ;
	// else
	// 	print_error()
}

void	open_map(t_data *cube)
{
	char	*tmp;
	char	*str;
	int		fd;

	fd = open(cube->file, O_RDONLY);
	if (fd < 0)
		print_error("Error: open fd.", EXIT_FAILURE);
	str = get_next_line(fd);
	while (str)
	{
		check_line(cube, str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
