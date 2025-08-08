/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:46:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/08 18:24:04 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int key_action(int keycode, t_data *cube)
{
    t_player *player = &cube->player;

    int speed = 5;
    float angle_speed = 0.1;
    float next_x = player->x;
    float next_y = player->y;
    
    if (keycode == XK_Escape)
        endgame(cube);
    if (keycode == XK_Right)
        cube->player.angle += angle_speed;
    if (keycode == XK_Left)
        cube->player.angle -= angle_speed;   
    if (keycode == XK_w)
    {
        next_x += cos(player->angle) * speed;
        next_y += sin(player->angle) * speed;
        if (!touch(next_x, next_y, cube))
        {
            player->x = next_x;
            player->y = next_y;
        }
    }
    if (keycode == XK_s)
    {
        next_x -= cos(player->angle) * speed;
        next_y -= sin(player->angle) * speed;
        if (!touch(next_x, next_y, cube))
        {
            player->x = next_x;
            player->y = next_y;
        }
    }
    if (keycode == XK_a)
    {
        next_x = player->x + sin(player->angle) * speed;
        next_y = player->y - cos(player->angle) * speed;
        if (!touch(next_x, next_y, cube))
        {
            player->x = next_x;
            player->y = next_y;
        }
    }
    if (keycode == XK_d)
    {
        next_x = player->x - sin(player->angle) * speed;
        next_y = player->y + cos(player->angle) * speed;
        if (!touch(next_x, next_y, cube))
        {
            player->x = next_x;
            player->y = next_y;
        }
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

