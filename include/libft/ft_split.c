/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:48:16 by kjolly            #+#    #+#             */
/*   Updated: 2025/02/07 15:28:45 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	unsigned int	in_word;
	int				count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count ++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malword(char const *s, int debut, int fin)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * ((fin - debut) + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (debut < fin)
	{
		word[i] = s[debut];
		i++;
		debut++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	unsigned int		i;
	int					j;
	int					start;
	char				**split;

	if (!s)
		return (NULL);
	split = malloc((sizeof(char *)) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	i = ((j = 0));
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j++] = malword(s, start, i);
			start = -1;
		}
		i++;
	}
	return (split[j] = 0, split);
}

// ? separe un tableau en tableau de tableau 
// ? a partir d'un separatreur "c"
// ! voir notes
/*int	main(void)
 {
 	char	*s = "xxxxhello";
 	char	c = 'x';
 	int		i = 0;
 	char	**split = ft_split(s, c);
 	if (!split)
 		return (0);
 	while(split[i])
 	{
 		printf("%s\n", split[i]);
 		i++;
 	}
 }*/
