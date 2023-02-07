/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:10:29 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/07 14:43:50 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	ft_win()
{

}

int	pick(t_rules *rules, int x, int y)
{
	if (rules->inpmap.map[y][x] == 'H')
		return (1);
	else if (rules->inpmap.map[y][x] == 'T')
		return (2);
	return (0);
}

void	collect(t_rules *rules)
{
	int	x;
	int	y;

	x = (int)(rules->player.x / rules->inpmap.block_width);
	y = (int)(rules->player.y / rules->inpmap.block_width);
	if (pick(rules, x, y) == 1)
	{
		rules->flag_hat = 1;
		rules->inpmap.map[y][x] = '0';
	}
	else if (pick(rules, x, y) == 2)
	{
		rules->flag_skull = 1;
		rules->inpmap.map[y][x] = '0';
	}
}

static int	is_open(t_rules *rules, int x, int y)
{
	if (rules->inpmap.map[y][x] == '*' && rules->flag_hat && rules->flag_skull)
		return (1);
	return (0);
}

void	ft_openexit(t_rules *rules)
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
	if (is_open(rules, x, y))
		rules->win_flag = 1;
	//ft_exit("u win\n");
}