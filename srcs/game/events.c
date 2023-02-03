/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:56:03 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/03 18:30:39 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static int	press(int key, t_rules *rules)
{
	if (key == 53)
	{
		mlx_destroy_window(rules->mlx.mlx, rules->mlx.mlx_win);
		exit(0);
	}
	if (key == 13)
		rules->keys.w_pressed = 1;
	if (key == 0)
		rules->keys.a_pressed = 1;
	if (key == 1)
		rules->keys.s_pressed = 1;
	if (key == 2)
		rules->keys.d_pressed = 1;
	if (key == 123)
		rules->keys.l_pressed = 1;
	if (key == 124)
		rules->keys.r_pressed = 1;
	if (key == 257 || key == 258)
		rules->keys.shift_pressed = 1;
	return (0);
}

static int	release(int key, t_rules *rules)
{
	if (key == 13)
		rules->keys.w_pressed = 0;
	if (key == 0)
		rules->keys.a_pressed = 0;
	if (key == 1)
		rules->keys.s_pressed = 0;
	if (key == 2)
		rules->keys.d_pressed = 0;
	if (key == 123)
		rules->keys.l_pressed = 0;
	if (key == 124)
		rules->keys.r_pressed = 0;
	if (key == 257 || key == 258)
		rules->keys.shift_pressed = 0;
	return (0);
}

static int	eexit(t_rules *rules)
{
	mlx_destroy_window(rules->mlx.mlx, rules->mlx.mlx_win);
	exit(0);
	return (0);
}

void	events(t_rules *rules)
{
	mlx_hook(rules->mlx.mlx_win, 2, 1L << 0, press, rules);
	mlx_hook(rules->mlx.mlx_win, 3, 1L << 1, release, rules);
	mlx_hook(rules->mlx.mlx_win, 17, 0, eexit, rules);
}
