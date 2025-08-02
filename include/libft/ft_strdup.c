/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:12:26 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/18 09:03:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
/*#include <stdio.h>*/

char	*ft_strdup(const char *src)
{
	char				*dst;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dst == NULL)
		return (NULL);
	while (src[i])
	{
		dst[j++] = src[i++];
	}
	dst[i] = '\0';
	return (dst);
}
// ? strdup permet de dupliquer une string
// ? en lui alouant la size d'une autre
/*int	main(void)
{
	char	src[] = "";
	ft_strdup(src);
	printf("%s\n", src);
}*/