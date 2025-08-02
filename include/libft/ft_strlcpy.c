/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:30:48 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/19 14:17:53 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <bsd/string.h>
#include <stdio.h>*/

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	unsigned int	i;

	i = 0;
	if (siz == 0)
		return (ft_strlen(src));
	while (i < siz - 1 && src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
// ? retourne la size len de source et copy la src dans la dest
/*int	main(void)
{
	char	dest[0];
	const char	src[] = "je suis la";
	size_t		siz = 9;
	
	printf("%zu\n", ft_strlcpy(dest, src, siz));
	printf("%s\n", dest);
	printf("%zu\n", strlcpy(dest, src, siz));
	printf("%s\n", dest);
}*/
