/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:00:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/04 11:42:01 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_xpm(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return ((!ft_strcmp(str + len - 5, ".xpm\n")));
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
	while(str[i] && str[i] == ' ')
		i++;
	if (!check_xpm(str))
		print_error("texture dois finir par \".xpm\".", 1);
	// if (!check_open(str))
	// 	print_error("texture invalide.", 1);
	if (type == NO && !cube->x_file.text_no)
		cube->x_file.text_no = ft_strdup(&str[i]);
	else if (type == SO && !cube->x_file.text_so)
		cube->x_file.text_so = ft_strdup(&str[i]);
	else if (type == WE && !cube->x_file.text_we)
		cube->x_file.text_we = ft_strdup(&str[i]);
	else if (type == EA && !cube->x_file.text_ea)
		cube->x_file.text_ea = ft_strdup(&str[i]);
}

void	check_color(t_data *cube, char *str, int type)
{
	int	i;
	int	k;
	int	value[3] = {0, 0, 0};
	int	final_value;

	i = 0;
	final_value = 0;
	k = 0;
	while(k < 3)
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]))
		{
			value[k] = value[k] * 10 + (str[i] - '0');
			i++;
		}
		if (value[k] < 0 || value[k] > 255)
			print_error("mauvais code rgb.", 1);
		while (str[i] == ' ')
			i++;
		if (k == 2 && str[i] != '\n')
			print_error("code rgb trop long.", 1);
		if (k < 2)
		{
			if (str[i] != ',')
				print_error("element invalide code rgb.", 1);
			i++;
		}
		k++;
	}
	final_value = (value[0] << 16) | (value[1] << 8) | value[2];
	if (type == F)
		cube->x_file.color_f = final_value;
	else if (type == C)
		cube->x_file.color_c = final_value;
}

void	check_line(t_data *cube, char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] == ' ')
		i++;
	if(str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		check_path(cube, str + i + 3, NO);
	else if(str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		check_path(cube, str + i + 3, SO);
	else if(str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		check_path(cube, str + i + 3, WE);
	else if(str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		check_path(cube, str + i + 3, EA);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		check_color(cube, str + i + 2, F);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		check_color(cube, str + i + 2, C);
	else if (str[i] == '1')
		return ;
	else if (str[i] == '\n')
		return ;
	 else
		print_error("rentre dans rien", 1);
}

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

	fd = open(cube->file, O_RDONLY);
	if (fd < 0)
		print_error("fd ouvert.", EXIT_FAILURE);
	str = get_next_line(fd);
	while (str)
	{
		check_line(cube, str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if(miss_line(cube))
		print_error("il manque un element.", 1);
	printf("%s\n", cube->x_file.text_no);
	printf("%s\n", cube->x_file.text_so);
	printf("%s\n", cube->x_file.text_we);
	printf("%s\n", cube->x_file.text_ea);
	printf("%d\n", cube->x_file.color_f);
	printf("%d\n", cube->x_file.color_c);

}
