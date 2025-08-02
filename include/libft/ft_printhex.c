/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:41:13 by kjolly            #+#    #+#             */
/*   Updated: 2024/12/14 14:33:05 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_printhex(unsigned int n, const char arg)
{
	int		i;
	char	*base;

	i = 0;
	if (arg == 'x')
		base = "0123456789abcdef";
	else if (arg == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	if (n >= 16)
		i += ft_printhex(n / 16, arg);
	i += ft_printchar(base[n % 16]);
	return (i);
}
/*
int	main()
{
	unsigned int	n = 156485;
	const char	arg = 'X';
	printf("%X\n", n);
	printf("\n%d\n", ft_printhex(n, arg));
}*/