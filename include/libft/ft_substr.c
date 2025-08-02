/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:58:00 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/23 10:35:27 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	temp = ft_strlen(s + start);
	if (temp > len)
		temp = len;
	dst = malloc(sizeof(char) * temp + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len && s[i + start])
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
// ? la fonction extrait une nouvelle chaine a partir d'une autre
// ? len = taille max de la nouvelle chaine
// ? start = index de debut de la nouvelle chaine
// ! start parcour la source string "n"
// ! i parcour la destination sans depassrr la taille max autoriser par len
/*int	main(void)
{
	const char	s[] = "hola";
	unsigned int start = 0;
	unsigned int len = 18446744073709551615;

	printf("%s\n", ft_substr(s,  start, len));
}*/
