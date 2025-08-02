/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:06 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/21 15:55:22 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *string, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)string);
	i = 0;
	while (string[i] && i < len)
	{
		j = 0;
		while ((string[i + j] == to_find[j]) && to_find[j] && (i + j) < len)
			j++;
		if (!to_find[j])
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}
// ? cherche la partie "find" de "str" en ne depassant pas la limite
// ? len imposer pour parcourir str.
// ! observation + explication :
// ? 29|on parcour str[i] et i doit totalement parcourir la len
// ? 32|les 3 conditions a suivres
// ? 37/38|quand on arrive a la fin de "find" on renvoie i - j,
// ? donc on retounera la ou i et j se sont suivis.
/*int	main(void)
{
	char	s[] = "aaxx";
	char	f[] = "xx";
	char	s1[] = "aaxx";
	char	f1[] = "xx";
	size_t	i = 5;
	
	printf("%s\n", ft_strnstr(s, f, i));
	printf("%s\n", strnstr(s1, f1, i));
}*/
