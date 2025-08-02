/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:32:44 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/28 11:18:33 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
// ? aloue une zone memoire et met tout les elemets a 0
/*int	main(void)
{
	unsigned char	s[] = "";
	size_t	n = 42;
	ft_bzero(s, n);
	printf("%", s);
}*/