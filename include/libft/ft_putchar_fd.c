/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:39:39 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/19 09:53:39 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
// ? ici la fonction write sera ecrite en fonction du "file descriptor"
// ! dans la fonction write :
// ! write(int fd, le charac, la taille du charac)
/*int	main(void)
{
	char	c = 'c';
	int		fd = 0;
	
	ft_putchar_fd(c, fd);
}*/