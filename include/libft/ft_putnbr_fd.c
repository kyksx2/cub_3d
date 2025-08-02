/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:33:02 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/19 10:50:15 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd (-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd ((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}
// ? fonction putnbr de base avec un ft_puchar_fd
/*int	main(void)
{
	int	i;
	int fd;
	fd = 1;
	i = 2147483647;
	ft_putnbr_fd(i, fd);
}*/