/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtounek <shtounek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:46:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/05 19:35:09 by shtounek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	moov_da_player()
// {
    
// }

// void	init_moov(int keycode, t_data *cube)
// {
//     double  move_speed = MOVE_SPEED;
//     double  angle = cube->player.angle;

// 	if (keycode == XK_w)
// 		moov_da_player();
// 	if (keycode == XK_a)
// 		moov_da_player();
// 	if (keycode == XK_s)
// 		moov_da_player();
// 	if (keycode == XK_d)
// 		moov_da_player();
//     if (keycode == XK_Left)
//         angle = cube->player.angle -= 0.1; 
//     if (keycode == XK_Right)
//         angle = cube->player.angle += 0.1; 
// }


int	key_action(int keycode, void *param)
{
	t_data	*cube;

	cube = (t_data *)param;
	if (keycode == XK_Escape)
		endgame(cube);
	// if (keycode == XK_w || keycode == XK_Up || keycode == XK_a
	// 	|| keycode == XK_Left || keycode == XK_s || keycode == XK_Down
	// 	|| keycode == XK_d || keycode == XK_Right)
	// 	init_moov(keycode, cube);
	// mlx_clear_window(cube->mlx, cube->win);
	// render(cube);
	return (0);
}

