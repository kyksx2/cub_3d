/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:20:39 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/20 15:20:08 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i--;
	}
	if (str[i] == (unsigned char)c)
		return (str + i);
	return (NULL);
}
// ? contrairement a strchr
// ? strrchr prend la derniere occurence de la string
/*int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_strrchr(av[1], av[2][0]));
	printf("%s\n", strrchr(av[1], av[2][0]));
}*/
