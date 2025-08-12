/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:46:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/12 17:52:33 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_action(int keycode, t_data *cube)
{
	double	speed;

	speed = 5;
	if (keycode == XK_Escape)
		endgame(cube);
	if (keycode == XK_Right)
		rotate(cube, 0.1);
	if (keycode == XK_Left)
		rotate(cube, -0.1);
	if (keycode == XK_w)
		move_up(cube, speed);
	if (keycode == XK_s)
		move_down(cube, speed);
	if (keycode == XK_a)
		move_left(cube, speed);
	if (keycode == XK_d)
		move_right(cube, speed);
	return (0);
}

// int key_action(int keycode, t_data *cube)
// {
//     t_player *player = &cube->player;

//     int speed = 5; // vitesse en pixels
//     if (keycode == XK_Escape)
//         exit (0);
//     if (keycode == XK_w)
//         player->y -= speed;    // !! version 2D
//     if (keycode == XK_a)
//         player->x -= speed;
//     if (keycode == XK_s)
//         player->y += speed;
//     if (keycode == XK_d)
//     {
//         player->x += speed;
//     }
// 	return (0);
// }
