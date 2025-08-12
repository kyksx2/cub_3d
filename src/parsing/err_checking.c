/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:35:48 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/12 22:46:12 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	clean_gnl_and_exit(t_data **cube, char *line, char *msg, int code)
{
	if (line)
	{
		free(line);
	}
	print_error(*cube, msg, code);
}

void	err_checking(t_data *cube, char *line, char *trimmed, char *msg)
{
	free(trimmed);
	clean_gnl_and_exit(&cube, line, msg, -1);
}
