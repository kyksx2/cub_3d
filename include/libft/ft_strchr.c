/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:36:32 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/20 17:14:53 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (str + i);
	return (NULL);
}
// ? la fonction renvoie la suite de la string s
// ? a partir de la premiere occurence c quelle trouve dans celle-ci
// ? si elle ne trouve rien elle renvoie null.
/*int	main(void)
{
	const char	s[] = "teste";
	int		c = '\0';
	const char	s2[] = "teste";
	int	c2 = '\0';
	
	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", strchr(s2, c2));
}*/
