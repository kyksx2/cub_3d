/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:17:18 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/19 09:38:48 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*void	f(unsigned int i, char *c)
{
	(c = c + i);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// ? idem que strmapi mais sans le malloc car elle ne renvoie rien
// ! elle prend l'adresse et non le caractere de la string s
/*int	main(void)
{
	char s[] = "je suis";
	ft_striteri(s, f);

}*/
