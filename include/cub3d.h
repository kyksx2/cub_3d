/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:19:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/04 16:24:02 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

#define LIMITE 500;

// x = colonne
// y = ligne
// ---------->x----------
// |                    |
// |                    |
// |                    |
// y                    |
// |                    |
// ----------------------
typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}			t_dir;

#define CUB_PIXEL 64; // ? 64 est une puissance de 2 et est souvent utiliser comme norme pour du raycasting

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

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}				t_player;

typedef struct s_data 
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*file;
	int			count_player;
	t_dir		type;
	t_player	player;
	t_file		x_file;
}				t_data;

// raycasting
void	render(t_data *cube);

// check text+color
void	open_map(t_data *cube);
int     start_map(char *line);
void	print_error(t_data *check, char *str, int i);

// Checking map
char    **convert_map(t_data *check, t_list *map_lines);
void    read_line(t_data *cube, int fd, char *first_map_line);
int		is_map_valid(char *str);
int		size_map(t_list *map_lines);
int		validate_map(t_data *verif);
int		is_wall(t_data *wall);
int     check_elements(t_data *elem);

#endif