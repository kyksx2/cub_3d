/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:31:29 by kjolly            #+#    #+#             */
/*   Updated: 2024/12/14 14:33:19 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdint.h>

static int	ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	ptrhex(uintptr_t ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		ptrhex(ptr / 16);
	ft_printchar(base[ptr % 16]);
}

int	ft_printptr(void *ptr)
{
	int				i;
	unsigned long	p;

	p = (unsigned long)ptr;
	i = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	else
	{
		write (1, "0x", 2);
		ptrhex(p);
		i = ptrlen(p);
	}
	return (i + 2);
}

/*int	main(void)
{
	char	*c = "1";
	printf("%p\n", c);
	printf("\n%d\n", ft_printptr(c));
	char	*n = "1";
	printf("%p\n", n);
	printf("\n%d\n", ft_printptr(n));
}*/
