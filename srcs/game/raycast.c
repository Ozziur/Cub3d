/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:05:11 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/24 15:42:45 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static void	draw_ceiling(t_rules *rules, t_image *view)
{
	int	x;
	int	y;

	x = -1;
	while (++x < rules->mlx.win_width)
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
	t_bres_data	data;

	data.ray_angle = increment_angle(rules->player.dir,
			rules->mlx.win_width / 2);
	data.x = 0;
	data.color = 0x00FFFFFF;
	draw_floor(rules, view);
	draw_ceiling(rules, view);
	while (data.x++ < rules->mlx.win_width - 1)
		raycast_calc(&data, rules, view, minimap);
}
