/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:46:08 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/03 18:46:10 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static unsigned int	choose_color(char c)
{
	if (c == '0')
		return (0x4F4F4F);
	else if (c == '1' || c == ' ')
		return (0X2F2F2F);
	else if (c == 'D' || c == 'd')
		return (0X654321);
	return (0x0);
}

static void	draw_mini_player(t_rules *rules, t_image *image)
{
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;

	start_x = (rules->player.x / 4) - (rules->inpmap.mini_block_width / 10);
	start_y = (rules->player.y / 4) - (rules->inpmap.mini_block_width / 10);
	end_x = (rules->player.x / 4) + (rules->inpmap.mini_block_width / 10);
	end_y = (rules->player.y / 4) + (rules->inpmap.mini_block_width / 10);
	while (start_y < end_y -1)
	{
		start_x = (rules->player.x / 4) - (rules->inpmap.mini_block_width / 10);
		while (start_x < end_x)
			easy_pxl(image, start_x++, start_y, 0x000000FF);
		start_y++;
	}
}

void	draw_mini_supp(t_rules *rules, int var[7], unsigned int color,
	t_image *image)
{
	if (rules->inpmap.map[var[4]][var[5]] == '4')
	{
		color = 0x000000FF;
		var[2] = var[4] * rules->inpmap.mini_block_width
			+ rules->inpmap.mini_block_width / 5;
		var[3] = var[2] + rules->inpmap.mini_block_width / 8 * 5;
		while (var[2] <= var[3])
		{
			var[6] += rules->inpmap.mini_block_width / 8;
			var[0] = var[6] + 1;
			var[1] = var[0] + rules->inpmap.mini_block_width / 2;
			while (var[0] <= var[1])
				easy_pxl(image, var[0]++, var[2], color);
			var[2]++;
		}
	}
}

static void	draw_mini_block(t_rules *rules, int i, int j, t_image *image)
{
	unsigned int	color;
	int				var_start_end_xy[7];

	var_start_end_xy[4] = i;
	var_start_end_xy[5] = j;
	color = choose_color(rules->inpmap.map[i][j]);
	var_start_end_xy[0] = j * rules->inpmap.mini_block_width;
	var_start_end_xy[1] = var_start_end_xy[0] + rules->inpmap.mini_block_width;
	var_start_end_xy[2] = i * rules->inpmap.mini_block_width;
	var_start_end_xy[3] = var_start_end_xy[2] + rules->inpmap.mini_block_width;
	var_start_end_xy[6] = var_start_end_xy[0];
	while (var_start_end_xy[2] < var_start_end_xy[3])
	{
		var_start_end_xy[0] = var_start_end_xy[6];
		while (var_start_end_xy[0] < var_start_end_xy[1])
			easy_pxl(image, var_start_end_xy[0]++, var_start_end_xy[2], color);
		var_start_end_xy[2]++;
	}
	draw_mini_supp(rules, var_start_end_xy, color, image);
}

void	minimap2d(t_rules *rules, t_image *minimap)
{
	int		i;
	int		j;

	i = -1;
	while (++i < rules->inpmap.map_height_len[1])
	{
		j = -1;
		while (++j < rules->inpmap.map_height_len[0])
			draw_mini_block(rules, i, j, minimap);
	}
	draw_mini_player(rules, minimap);
}
