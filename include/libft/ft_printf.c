/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:26:46 by kjolly            #+#    #+#             */
/*   Updated: 2024/12/14 15:43:37 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	conversion(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_printchar(va_arg(args, int));
	if (format == '%')
		i += ft_printchar('%');
	if (format == 's')
		i += ft_printstr(va_arg(args, char *));
	if (format == 'i')
		i += ft_printnbr(va_arg(args, int));
	if (format == 'd')
		i += ft_printnbr(va_arg(args, int));
	if (format == 'u')
		i += ft_printunsi(va_arg(args, unsigned int));
	if (format == 'p')
		i += ft_printptr(va_arg(args, void *));
	if (format == 'x' || format == 'X')
		i += ft_printhex(va_arg(args, int), format);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += conversion(args, s[i + 1]);
			i++;
		}
		else
			count += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main()
{
	printf("%d\n", ft_printf("% d\n", 101));
	printf("%d\n", printf("% d\n", 101));
}*/
