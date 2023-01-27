/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:00:40 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/27 15:42:23 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	mouse(int x, int y, t_rules *rules)
{
	if (!rules->mouse.moved)
	{
		rules->mouse.moved = 1;
		rules->mouse.x = x;
		rules->mouse.y = y;
	}
	move_mouse(x, y, rules);
	rules->player.d_x = cos(rules->player.dir);
	if (rules->player.dir == (double)M_PI)
		rules->player.d_y = 0;
	else
		rules->player.d_y = -sin(rules->player.dir);
	return (0);
}