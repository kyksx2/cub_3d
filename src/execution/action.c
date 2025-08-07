/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:46:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/06 16:43:51 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int key_action(int keycode, t_data *cube)
{
    double speed = 5.0; // vitesse en pixels

    if (keycode == XK_Up) // W
        cube->player.y -= speed;
    else if (keycode == XK_Down) // S
        cube->player.y += speed;
    else if (keycode == XK_Left) // A
        cube->player.x -= speed;
    else if (keycode == XK_Right) // D
        cube->player.x += speed;
    execution(cube);
    return (0);
}

