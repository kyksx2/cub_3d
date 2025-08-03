/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:19:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/03 19:52:36 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

#define LIMITE 500;

#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 4
#define C 5

typedef struct s_file
{
	char	*text_no;
	char	*text_so;
	char	*text_we;
	char	*text_ea;
	int		color_f;
	int		color_c;
	char	**map;
}			t_file;

typedef struct s_data 
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*file;
	t_file	x_file;
}			t_data;

void	open_map(t_data *cube);
void	print_error(char *str, int i);

// Checking map
char	**convert_map(t_list *map_lines);
t_list	*read_line(t_data *check);
int		is_map_valid(char *str);
int		size_map(t_list *map_lines);
int		ft_strcspn(char *str, char reject);
int		validate_map(t_data *verif);
int		is_wall(t_data *wall);

#endif