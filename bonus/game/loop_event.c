/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:01 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/09 17:38:06 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	let_keys_aux(t_rules *rules)
{
	if (rules->keys.l_pressed)
	{
		rules->player.dir = increment_angle(rules->player.dir, 40);
		rules->player.plane = increment_angle(rules->player.plane, 40);
	}
	if (rules->keys.r_pressed)
	{
		rules->player.dir = decrement_angle(rules->player.dir, 40);
		rules->player.plane = decrement_angle(rules->player.plane, 40);
	}
	if (rules->keys.f_pressed)
		ft_doors(rules);
	if (rules->keys.space_pressed)
		ft_openexit(rules);
	rules->player.d_x = cos(rules->player.dir);
	if (rules->player.dir == (double)M_PI)
		rules->player.d_y = 0;
	else
		rules->player.d_y = -sin(rules->player.dir);
	rules->player.plane_x = -cos(rules->player.plane);
	rules->player.plane_y = sin(rules->player.plane);
}

void	let_keys_work(t_rules *rules)
{
	if (rules->keys.a_pressed)
		moves(rules, 'a');
	if (rules->keys.s_pressed)
		moves(rules, 's');
	if (rules->keys.d_pressed)
		moves(rules, 'd');
	if (rules->keys.w_pressed)
		moves(rules, 'w');
	if (rules->keys.shift_pressed)
		rules->player.speed = SPEED * 2;
	else
		rules->player.speed = SPEED;
	let_keys_aux(rules);
}

int	loop_events(t_rules *rules)
{
	if (!(rules->n_frames % 170))
	{
		let_keys_work(rules);
		if (rules->win_flag == 0)
			game(rules);
		else if (!rules->won)
			ft_win(rules);
		rules->n_frames++;
	}
	else
		rules->n_frames++;
	return (0);
}
