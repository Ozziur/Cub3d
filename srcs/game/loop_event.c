/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:01 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/24 15:59:27 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	let_keys_aux(t_rules *rules)
{
	if (rules->keys.l_pressed)
		rules->player.dir = increment_angle(rules->player.dir, 40);
	if (rules->keys.r_pressed)
		rules->player.dir = decrement_angle(rules->player.dir, 40);
	rules->player.d_x = cos(rules->player.dir);
	if (rules->player.dir == (double)M_PI)
		rules->player.d_y = 0;
	else
		rules->player.d_y = -sin(rules->player.dir); 
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
	if (!rules->keys.shift_pressed)
		rules->player.speed = SPEED;
	let_keys_aux(rules);
}

int	loop_events(t_rules *rules)
{
	let_keys_work(rules);
	//creare condidione che si basa sul numero di frame da vedere
	game(rules);
	return (0);
}
