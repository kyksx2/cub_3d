/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:17:34 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/20 12:50:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	const char		*sr;
	unsigned int	i;

	dst = dest;
	sr = src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dest);
}
// ? copie n bytes de src vers dest.
/*int	main(void)
{
	unsigned char	dst[] = "je suis";
	const char		sr [] = "baba";
	unsigned int	n = 2;

	ft_memcpy(dst, sr, n);
	printf("%s\n%s\n", dst, sr);
	memcpy(dst, sr, n);
	printf("%s\n%s\n", dst, sr);
}*/