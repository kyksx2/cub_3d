/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:12:48 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/20 15:09:00 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*sr;
	unsigned int		i;

	dst = dest;
	sr = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > sr)
	{
		while (n--)
			dst[n] = sr[n];
	}
	else
	{
		while (n--)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
//! a la difference de memcpy,
//! memmove prend la condition ou les 2 variables se chevauchent.
/*int	main(void)
{
	char	str1[] = "coucou";
	char	str2[] = "coucou";

	printf("%s\n", str1);
	memmove (str1+2, str1, sizeof(char)*3);
	printf("%s\n\n", str1);

	printf("%s\n", str2);
	ft_memmove (str2+2, str2, sizeof(char)*3);
	printf("%s\n", str2);
}*/
