/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:35 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/24 15:58:22 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static void	adjust_var(double var[2], t_rules *rules)
{
	if (var[0] < 0)
		var[0] = 0;
	if (var[1] > rules->mlx.win_height)
		var[1] = rules->mlx.win_height;
}

static void	draw_walls(double var[2], t_rules *rules, t_draw_info *info)
{
	var[0] = rules->mlx.win_height / 2 - info->l_h /2;
	if (var[0] < 0)
		var[0] = 0;
	while (var[0] < var[1])
	{
		if (!our_modulo(info->d.xy2[0], rules->inpmap.block_width))
			easy_pxl(info->view, info->d.x, var[0], color_pxl(info->tex,
					choose_x(info, info->d.xy2[1], rules), choose_y(var[0],
						info), rules));
		else
			easy_pxl(info->view, info->d.x, var[0], color_pxl(info->tex,
					choose_x(info, info->d.xy2[0], rules), choose_y(var[0],
						info), rules));
		var[0]++;
	}
	
}

void	draw_view(t_bres_data *d, t_image *view, t_rules *rules, t_image *tex)
{
	t_draw_info	info;
	double		dist;
	double		var[2];

	dist = get_dist(rules, d);
	info.l_h = rules->inpmap.block_width * rules->mlx.win_height / dist;
	var[0] = rules->mlx.win_height / 2 - info.l_h / 2;
	var[1] = info.l_h + var[0];
	info.view = view;
	info.tex = tex;
	info.d = *d;
	adjust_var(var, rules);
	draw_walls(var, rules, &info);
}