/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:07:40 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/13 16:19:09 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_path(t_data *cube, char *str, int type)
{
	char	*trimmed;
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	trimmed = ft_strtrim(&str[i], " \n\r\t");
	if (!trimmed)
		return (printf("Erreur: allocation echouer.\n"), 0);
	if (!check_xpm(trimmed))
	{
		free(trimmed);
		return (printf("Erreur: la texture doit finit par \"xpm\".\n"), 0);
	}
	if (!check_open(trimmed))
	{
		free(trimmed);
		return (printf("Erreur: echec ouverture texture.\n"), 0);
	}
	if (type == NO && !cube->x_file.text_no)
	{
		cube->x_file.text_no = ft_strdup(trimmed);
		return (free(trimmed), 1);
	}
	else if (type == SO && !cube->x_file.text_so)
	{
		cube->x_file.text_so = ft_strdup(trimmed);
		return (free(trimmed), 1);
	}
	else if (type == WE && !cube->x_file.text_we)
	{
		cube->x_file.text_we = ft_strdup(trimmed);
		return (free(trimmed), 1);
	}
	else if (type == EA && !cube->x_file.text_ea)
	{
		cube->x_file.text_ea = ft_strdup(trimmed);
		return (free(trimmed), 1);
	}
	return (1);
}

int	check_line(t_data *cube, t_list *line)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)line->content;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
	{
		if (!check_path(cube, str + i + 3, NO))
			return (0);
	}
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
	{
		if (!check_path(cube, str + i + 3, SO))
			return (0);
	}
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
	{
		if (!check_path(cube, str + i + 3, WE))
			return (0);
	}
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
	{
		if (!check_path(cube, str + i + 3, EA))
			return (0);
	}
	else if (str[i] == 'F' && str[i + 1] == ' ')
	{
		if (!check_color(cube, str + i + 2, F))
			return (0);
	}
	else if (str[i] == 'C' && str[i + 1] == ' ')
	{
		if (!check_color(cube, str + i + 2, C))
			return (0);
	}
	else if (str[i] == '1')
		return (1);
	else if (str[i] == '\n')
		return (1);
	else
		return (0);
	return (1);
}

void	check_list(t_data *cube, t_list *abdelweshzerhma, int fd)
{
	t_list *tmp;
	int		indice_free;

	indice_free = 0;
	tmp = abdelweshzerhma;
	while(tmp)
	{
		if (!check_line(cube, tmp))
		{
			indice_free = 1;
			break;
		}
		tmp = tmp->next;
	}
	free_list(&abdelweshzerhma);
	if (indice_free)
	{
		close(fd);
		print_error(cube, "error", -1);
	}
}

void	jojo_bizzare_aventure(t_data *cube)
{
	int		fd;
	char	*str;
	t_list	*abdelweshzerhma;

	fd = open(cube->file, O_RDONLY);
	if (fd < 0)
		print_error(cube, "fd ouvert.", EXIT_FAILURE);
	abdelweshzerhma = NULL;
	str = get_next_line(fd);
	while (str)
	{
		ft_lstadd_back(&abdelweshzerhma, ft_lstnew(str));
		str = get_next_line(fd);
	}
	check_list(cube, abdelweshzerhma, fd);
	close(fd);
}
