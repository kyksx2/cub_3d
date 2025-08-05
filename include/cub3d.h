/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:19:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/05 19:34:49 by shtounek         ###   ########.fr       */
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
#define	MOVE_SPEED 4.0; // ? valeur par defaut a ajuster pour la vitesse

#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 4
#define C 5

typedef struct s_texture
{
	void	*img; // mlx_xpm_file_to_immage()
	char	*addr; // mlx_get_data_addr()
	int		height; // donner remplies par mlx_xpm_file_to_immage()
	int		width; // donner remplies par mlx_xpm_file_to_immage()
	int		bpp; // bits par pixels, a voir plus  tard
	int		line_len; // taille d'une ligne de pixels
	int		endian; // ordre es octets
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
}				t_player;

typedef struct s_data 
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*file;
	int			count_player;
	t_texture	texture[4];
	t_dir		type;
	t_player	player;
	t_file		x_file;
}				t_data;

// Check text+color
void	open_map(t_data *cube);

// Check_open
int		check_xpm(char *str);
int		check_open(char *str);

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
void	err_free(t_data *err);
void    print_error(t_data *data, char *str, int i);
void	map_error(t_list *error, char **map, int i);
void	print_error(t_data *check, char *str, int i);

// -------------------- E X E C U T I O N ----------------------------

// raycasting
void	render(t_data *cube);

// mouvement
int	key_action(int keycode, void *param);
int	endgame(t_data *cube);

#endif