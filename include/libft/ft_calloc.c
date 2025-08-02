/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:21:06 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/21 17:34:51 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t ecount, size_t esize)
{
	void	*str;

	str = malloc(ecount * esize);
	if (!str)
		return (NULL);
	ft_bzero(str, (ecount * esize));
	return (str);
}
// ? ecount = nombre de bytes
// ? esize = taille des ecount
// ? calloc alloue une zone memoire pour un bloc memoire
// ! contrairement a malloc, elle initialise chaque octets a 0
//? 24| malloc doit donner le nombre d'elemets x leur taille (ici 0).
/*int	main(void)
{
	unsigned int	ecount = 10;
	unsigned int	esize = 8;
	char	*p1 = calloc(ecount, esize);
	char	*p2 = ft_calloc(ecount, esize);

	printf("1:%s\n", p1);
	printf("2:%s\n", p2);
	free(p1);
	free(p2);
}*/
