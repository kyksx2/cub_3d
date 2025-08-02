/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:21:18 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/19 10:32:31 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	write (fd, "\n", 1);
}
// ? idem que ft_putstr_fd mais il rajoute un "\n" a la fin
/*int	main(void)
{
	int	fd = 1;
	char s[] = "";
	
	ft_putendl_fd(s, fd);
}*/