/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:19:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/07 17:30:05 by shtounek         ###   ########.fr       */
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

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif


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

#define WIDTH 1280
#define HEIGHT 720

#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 4
#define C 5

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
}			t_texture;

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
}			t_player;

typedef struct s_data 
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*file;
	int			count_player;
	t_texture	texture;
	t_dir		type;
	t_player	player;
	t_file		x_file;
}				t_data;

void	init_all(t_data *init, char *file);

// Check text+color
void	open_map(t_data *cube);

// Check_open
int		check_xpm(char *str);
int		check_open(char *str);
void	final_map(t_data *game);

// Checking map
char    **convert_map(t_data *check, t_list *map_lines);
void    read_line(t_data *cube, int fd, char *first_map_line);
int		is_map_valid(char *str);
int		size_map(t_list *map_lines);
int		validate_map(t_data *verif);
int		is_wall(t_data *wall);
int     check_elements(t_data *elem);

// Utils
void	print_map(t_data *cube);
int		tounekti(char c);
int		sheinez2(char c);
int		start_map(char *line);

// Free / errors
void 	free_map(t_data *err);
void    print_error(t_data *data, char *str, int i);
void	map_error(t_list *error, char **map, int i);
void	print_error(t_data *check, char *str, int i);
void	free_cube(t_data *cube);

// -------------------- E X E C U T I O N ----------------------------

// raycasting
int execution(t_data *cube);

// mouvement
int	key_action(int keycode, t_data *cube);
int	endgame(t_data *cube);

#endif