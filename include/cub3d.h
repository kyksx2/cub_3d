/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:19:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/02 21:32:13 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include "./libft/libft.h"
#include "./mlx_linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

#define LIMITE 500;

typedef struct s_file
{
	char	*text_no;
	char	*text_so;
	char	*text_we;
	char	*text_ea;
	char	*color_f;
	char	*color_c;
	char	**map;
}			t_file;

typedef struct s_data 
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_file	x_file;
}			t_data;

void	open_map(t_data *cube, char *av);
void	print_error(char *str, int i);

#endif