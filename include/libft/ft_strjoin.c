/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:20:07 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/18 08:59:47 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*#include <stdio.h>*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}
// ? alloue de la memoir pour concatener 2 string dans une seule
// ! utiliser strlen pour la taille du maloc
// ! pour la concatenation, meme idee que strcat.
/*int	main(void)
{
	char const s1[] = "je ";
	char const s2[] = "";

	printf("%s\n", ft_strjoin(s1, s2));
}*/