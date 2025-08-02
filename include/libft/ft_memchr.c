/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:22:10 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/20 18:55:34 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
// ? cherche la 1ere occurence d'un element d'un block memoire
// ? et renvoie un pointeur vers celle-ci.
/*int	main(void)
{
	unsigned char s[] = "je suis kyllian";
	int	c = 'k';
	unsigned char s1[] = "je suis kyllian";
	int	c1 = 'k';
	unsigned int n = 10;
	
	ft_memchr(s, c, n);
	printf("%s\n", s);
	memchr(s1, c1, n);
	printf("%s\n", s1);
}*/
