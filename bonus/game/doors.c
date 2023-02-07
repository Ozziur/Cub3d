/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:19:06 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/07 12:50:38 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	is_door(int x, int y, t_rules *rules)
{
	if (rules->inpmap.map[y][x] == 'D' || rules->inpmap.map[y][x] == 'd')
		return (1);
	return (0);
}

void	change_door(int x, int y, t_rules *rules)
{
	if (rules->inpmap.map[y][x] == 'D')
	{
		rules->inpmap.map[y][x] = 'd';
		init_door(1, rules);
	}
	else if (rules->inpmap.map[y][x] == 'd')
	{
		rules->inpmap.map[y][x] = 'D';
		init_door(0, rules);
	}
}

void	ft_doors(t_rules *rules)
{
	int	x;
	int	y;

	x = (int)(rules->player.x / rules->inpmap.block_width);
	y = (int)(rules->player.y / rules->inpmap.block_width);
	if (rules->player.dir < M_PI / 4 || rules->player.dir > 2 * M_PI - M_PI / 4)
		x++;
	if (rules->player.dir > M_PI + M_PI / 4
		&& rules->player.dir < 2 * M_PI - M_PI / 4)
		y++;
	if (rules->player.dir > M_PI / 4 && rules->player.dir < M_PI - M_PI / 4)
		y--;
	if (rules->player.dir > M_PI - M_PI / 4
		&& rules->player.dir < M_PI + M_PI / 4)
		x--;
	if (is_door(x, y, rules))
	{
		change_door(x, y, rules);
		rules->keys.f_pressed = 0;
	}
}
