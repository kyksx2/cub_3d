/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:34:48 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/27 14:21:17 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	count(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		count ++;
	while (n > 0)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nb;

	nb = n;
	len = count(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[len--] = '\0';
	while (nb != 0)
	{
		str[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
// ? permet de transformer un int en char
// ! voir notes
/*int	main(void)
{
	int	n = 20007;

	printf("%s\n", ft_itoa(n));
}*/