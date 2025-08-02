/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:51:44 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/20 15:53:04 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dest);
	if (lendst >= s)
		return (lensrc + s);
	while (src[i] && lendst + i < s - 1)
	{
		dest[lendst + i] = src[i];
		i++;
	}
	dest[lendst + i] = '\0';
	return (lendst + lensrc);
}
// ? s est la taille total que peut atteindre dst
// ? 1er cas :
// ? dest > s --> on renvoie src + la taille que devait avoir la chaine.
// ? 2eme cas :
// ? dest < s --> on renvoie la taille final de la chaine.
// ! c'est  un  strcat avec 2 conditions en plus.
/*int	main(void)
{
	char	dest[] = "";
	char	dest2[] = "";
	const char	src[] = "123";
	const char	src2[] = "123";
	unsigned int	s = 0;

	printf("%zu\n", ft_strlcat(dest, src, s));
	printf("%s\n", dest);
	printf("%zu\n", strlcat(dest2, src2, s));
	printf("%s\n", dest2);
}*/
