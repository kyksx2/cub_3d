/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:25:16 by kjolly            #+#    #+#             */
/*   Updated: 2024/12/14 14:33:10 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_printnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (n < 0)
	{
		i += ft_printchar('-');
		i += ft_printnbr(-n);
	}
	else if (n >= 10)
	{
		i += ft_printnbr(n / 10);
		i += ft_printchar(n % 10 + '0');
	}
	else
		i += ft_printchar(n + '0');
	return (i);
}
/*int	main()
{
	int	n = 123456;
	printf("\n%d\n", ft_printnbr(n));
	printf("\n%d\n", n);
}*/