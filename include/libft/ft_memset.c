/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:16:54 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/19 16:39:18 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
/*int	main(void)
{
	char ptr[] = "je suis";
	
	ft_memset(ptr, '0', 3);
	printf("%s", ptr);
}*/
// aloue une zone memoire avec la meme valeurs dans chaques parties du tableau
// ? unsigned car les octets sont positifs
