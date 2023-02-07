/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colliding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:22:16 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/07 17:51:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

/*
next_c -> minimappa
act -> posizione del player
next -> mappa
*/

static int	verify(t_rules *rules, int next[2])
{
	if (next[0] < 0 || next[1] < 0
		|| next[0] > rules->inpmap.map_height_len[0]
		|| next[1] > rules->inpmap.map_height_len[1])
		return (1);
	if (rules->inpmap.map[next[1]][next[0]] == '1'
		|| rules->inpmap.map[next[1]][next[0]] == 'D'
		|| rules->inpmap.map[next[1]][next[0]] == '*')
		return (1);
	return (0);
}

static void	get_next(t_rules *rules, float sin_cos[2], int next[2], int flag)
{
	if (flag)
	{
		next[0] = (rules->player.x + sin_cos[1]) / rules->inpmap.block_width;
		next[1] = (rules->player.y + sin_cos[0]) / rules->inpmap.block_width;
	}
	else
	{
		next[0] = (rules->player.x - sin_cos[1]) / rules->inpmap.block_width;
		next[1] = (rules->player.y - sin_cos[0]) / rules->inpmap.block_width;
	}
}

static void	get_next_c(t_rules *rules, float sin_cos[2],
	int next_c[2], int flag)
{
	if (flag)
	{
		next_c[0] = (rules->player.x + sin_cos[1]);
		next_c[1] = (rules->player.y + sin_cos[0]);
	}
	else
	{
		next_c[0] = (rules->player.x - sin_cos[1]);
		next_c[1] = (rules->player.y - sin_cos[0]);
	}
}

int	colliding(t_rules *rules, float rcos, float rsin, int plus)
{
	int		next_c[2];
	int		act[2];
	int		next[2];
	float	sin_cos[2];

	act[0] = rules->player.x / rules->inpmap.block_width;
	act[1] = rules->player.y / rules->inpmap.block_width;
	sin_cos[0] = rsin;
	sin_cos[1] = rcos;
	if (plus)
	{
		get_next(rules, sin_cos, next, 1);
		get_next_c(rules, sin_cos, next_c, 1);
	}
	else
	{
		get_next(rules, sin_cos, next, 0);
		get_next_c(rules, sin_cos, next_c, 0);
	}
	if (act[0] != next[0] || act[1] != next[1]
		|| !(our_modulo(next_c[0], (int)rules->inpmap.block_width))
		|| !(our_modulo(next_c[1], (int)rules->inpmap.block_width)))
		return (verify(rules, next));
	return (0);
}
