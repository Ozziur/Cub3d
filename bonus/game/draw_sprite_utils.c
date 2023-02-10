/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:51:55 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/09 18:34:22 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	flag(void)
{
	static int		counter = 0;
	static bool		flag = 0;

	counter++;
	if (counter == 25)
		flag = 1;
	if (counter == 50)
	{
		flag = 0;
		counter = 0;
	}
	return (flag);
}

void	draw_sprite_col(t_rules *rules, t_draw_coord *info,
	t_image *view, double trans_y)
{
	if (trans_y > 0 && info->start_x > 0 && info->start_x < rules->mlx.win_width
		&& trans_y < rules->dist_array[(int)info->start_x])
	{
		info->start_y = info->bench_y;
		if (info->start_y <= 0)
			info->start_y *= -1;
		while (info->start_y < info->end_y)
		{
			info->t_y = (int)((info->start_y - info->bench_y)
					* info->sprite->height / info->height);
			info->color = get_sprite_color(info->sprite, info->t_x,
					info->t_y, rules);
			if (info->color)
				easy_pxl(view, info->start_x, info->start_y, info->color);
			info->start_y++;
		}
	}
}
