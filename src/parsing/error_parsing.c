/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:35:48 by shtounek          #+#    #+#             */
/*   Updated: 2025/08/13 17:52:04 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

void	map_error(t_list *error, char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_lstclear(&error, free);
	ft_printf("Erreur : echec de l'allocation de la map.\n");
	// exit(-1);
}
