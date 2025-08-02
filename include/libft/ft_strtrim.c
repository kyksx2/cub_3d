/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:04:34 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/26 18:01:02 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found_set;

	i = 0;
	while (s1[i])
	{
		j = 0;
		found_set = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found_set = 1;
				break ;
			}
			j++;
		}
		if (!found_set)
			break ;
		i++;
	}
	return (i);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found_set;

	i = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (-1);
	while (i >= 0)
	{
		j = 0;
		found_set = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found_set = 1;
				break ;
			}
			j++;
		}
		if (!found_set)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start > end)
	{
		trim = malloc(sizeof(char));
		if (!trim)
			return (NULL);
		trim[0] = '\0';
		return (trim);
	}
	trim = malloc(sizeof(char) * (end - start + 2));
	if (!trim)
		return (NULL);
	i = 0;
	while (start <= end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}

/*int	main(void)
{
	char const s1[] = "miamoiseaumiam";
	char const set[] =  "miam";

	printf("%d\n", find_end(s1, set));
	printf("%d\n", find_start(s1, set));
	printf("%s\n", ft_strtrim(s1, set));

}*/