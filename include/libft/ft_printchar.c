/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:34:02 by kjolly            #+#    #+#             */
/*   Updated: 2024/12/14 14:32:49 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_printchar(char d)
{
	return (write (1, &d, 1));
}
/*
int	main(void)
{
	char	d = 'c';
	printf("\n%d\n", ft_printchar(d));
	printf("offi: %d\n", printf("%c", d));
}*/