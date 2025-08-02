/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:49:11 by kjolly            #+#    #+#             */
/*   Updated: 2024/12/14 14:33:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_printunsi(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_printunsi(n / 10);
	i += ft_printchar(n % 10 + '0');
	return (i);
}

/*int	main()
{
	unsigned int	n = 4294967295;
	printf("\n%d\n", ft_printunsi(n));
}*/