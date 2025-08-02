/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:37:30 by kjolly            #+#    #+#             */
/*   Updated: 2024/11/14 15:56:55 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	nb;

	nb = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}
// ? transforme un chara ascii en int.
// 1ere etape : passer tout les white spaces
// 2eme etape : si le signe est - on change "int signe" en negatif
// 3eme etape : parcour si les chiffres pour les passe en int
// nb * 10(deplace la virgule) + str[i] - 0 table ascii
/*int	main(void)
{
	const char str[] = "-0";
	printf("%d\n", (atoi)(str));
	printf("%d\n", atoi(str));
}*/