/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:19:44 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/14 16:53:30 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define LIMITE 500;

// #ifndef M_PI
// # define M_PI 3.14159265358979323846
// #endif

# define FOV 60.0f

// x = colonne
// y = ligne
// ---------->x----------
// |                    |
// |                    |
// |                    |
// y                    |
// |                    |
// ----------------------

# define WIDTH 1280
# define HEIGHT 720

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEIL,
}			t_dir;

typedef struct s_mini_map
{
	int	x;
	int	y;
	int	color;
	int	size;
}		t_mini_map;

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		width;
	int		height;
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
	char	*text_floor;
	char	*text_ceiling;
	int		color_f;
	int		color_c;
	char	**map;
}			t_file;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	double	dir_x;
	double	dir_y;
}			t_player;

typedef struct s_fov
{
	float	fov_radian;
	float	camera_planelenght;
	float	camera_planex;
	float	camera_planey;
}			t_fov;

typedef struct s_raycast
{
	float	ray_dirx;
	float	ray_diry;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	float	delta_distx;
	float	delta_disty;
	float	side_distx;
	float	side_disty;
	float	prepwallwist;
	int		height;
	int		drawstart;
	int		drawend;
}			t_raycast;

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
	t_texture	main_img;
	t_texture	floor;
	t_texture	ceil;
	t_fov		fov_raycast;
	t_raycast	raycasting;
	t_file		x_file;
	t_mini_map	mini;
}				t_data;

typedef struct s_garmin
{
	float	wall_x;
	int		face;
	int		tex_x;
	int		tex_y;
	float	step;
	float	tex_pos;
	int		color;
	int		start_y;
	int		end_y;
	int		y;
}			t_garmin;

void	init_all(t_data *init, char *file);
void	load_img(t_data *cube, t_texture *texture, char *str);

// Check text+color
void	open_map(t_data *cube);
int		check_color(t_data *cube, char *str, int type);
int		check_path(t_data *cube, char *str, int type);
int		check_line(t_data *cube, t_list *line);
void	jojo_bizzare_aventure(t_data *cube);

// Check_open
int		check_xpm(char *str);
int		check_open(char *str);
void	final_map(t_data *game);

// Checking map
char	**convert_map(t_data *check, t_list *map_lines);
void	read_line(t_data *cube, int fd, char *first_map_line);
int		is_map_valid(char *str);
int		size_map(t_list *map_lines);
int		validate_map(t_data *verif);
int		is_wall(t_data *wall);
int		check_elements(t_data *elem);

// Utils
void	print_map(t_data *cube);
int		player(char c);
int		sheinez2(char c);
int		start_map(char *line);

// Free / errors
void	free_map(t_data *err);
void	print_error(t_data *data, char *str, int i);
void	map_error(t_list *error, char **map, int i);
void	print_error(t_data *check, char *str, int i);
void	free_cube(t_data *cube);
void	free_list(t_list **list);

// Init
void	init_ray(t_data *cube);
int		init_game(t_data *cube);
void	load_img(t_data *cube, t_texture *texture, char *str);
void	init_player(t_data *cube);
void	init_fov(t_fov *fov, t_player *player);
void	ok_garmin_initialise_la_structure(t_garmin	*tex, t_raycast *ray);

// -------------------- E X E C U T I O N ----------------------------

// dist
float	distance(float x, float y);
float	fixed_dist(float px, float py, t_data *cube);
void	calcul_dist_x(t_player *player, t_raycast *ray);
void	calcul_dist_y(t_player *player, t_raycast *ray);

// raycasting
int		touch(float px, float py, t_data *cube);
int		execution(t_data *cube);
void	raycast(t_data *cube, float cameraX, int screenX);

// mouvement
void	rotate(t_data *cube, double rot);
void	move_up(t_data *cube, double speed);
void	move_down(t_data *cube, double speed);
void	move_left(t_data *cube, double speed);
void	move_right(t_data *cube, double speed);
int		key_action(int keycode, t_data *cube);
int		endgame(t_data *cube);

// texture
void	killer_queen(t_data *cube, t_raycast *ray, int screenX,
			t_player *player);
void	put_pixel(int x, int y, int color, t_data *game);
int		get_pixel(t_texture *t, int x, int y);
void	floor_ceiling_looping(t_garmin *tex, t_data *cube, int sX);
int		find_face(t_raycast *ray);

#endif