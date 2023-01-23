/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:05:11 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/23 16:09:13 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static void	draw_ceiling(t_rules *rules, t_image *view)
{
	int	x;
	int	y;

	x = -1;
	while (++x < rules->mlx.win_width - 1)
	{
		y = 0;
		while (y < rules->mlx.win_height / 2)
			easy_pxl(view, x, y++, get_color_arr(rules->inpmap.c_color));
	}
}

static void	draw_floor(t_rules *rules, t_image *view)
{
	int	x;
	int	y;

	x = -1;
	while (++x < rules->mlx.win_width)
	{
		y = rules->mlx.win_height / 2 - 1;
		while (++y < rules->mlx.win_height)
			easy_pxl(view, x, y, get_color_arr(rules->inpmap.f_color));
	}
}

void	raycast(t_rules *rules, t_image *view, t_image *minimap)
{
	draw_ceiling(rules, view);
	draw_floor(rules, view);
}