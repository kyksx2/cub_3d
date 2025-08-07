/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:46:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/07 17:49:40 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int key_action(int keycode, t_data *cube)
{
    t_player *player = &cube->player;

    int speed = 5;
    float angle_speed = 0.1;
    
    if (keycode == XK_Escape)
        exit (0);
    if (keycode == XK_Right)
        cube->player.angle += angle_speed;
    if (keycode == XK_Left)
        cube->player.angle -= angle_speed;   
    if (keycode == XK_w)
    {
        player->x -= cos(player->angle) * speed;
        player->y -= sin(player->angle) * speed;
    }
    if (keycode == XK_s)
    {
        player->x += cos(player->angle) * speed;
        player->y += sin(player->angle) * speed;
    }
    if (keycode == XK_a)
    {
        player->x -= sin(player->angle) * speed;
        player->y += cos(player->angle) * speed;
    }
    if (keycode == XK_d)
    {
        player->x += sin(player->angle) * speed;
        player->y -= cos(player->angle) * speed;
    }
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

