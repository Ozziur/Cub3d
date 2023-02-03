/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:05:11 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/03 17:18:09 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	virtual_horizontal_colliding(int ray_x, int ray_y, t_rules *rules, int dir)
{
	int	map_x;
	int	map_y;

	map_x = ray_x / rules->inpmap.block_width;
	if (!dir)
		map_y = ray_y / rules->inpmap.block_width - 1;
	else
		map_y = ray_y / rules->inpmap.block_width;
	if (map_x < 0 || map_y < 0
		|| map_x > rules->inpmap.map_height_len[0] - 1
		|| map_y > rules->inpmap.map_height_len[1] - 1)
		return (1);
	if (rules->inpmap.map[map_y][map_x] == '1'
		|| rules->inpmap.map[map_y][map_x] == 'D'
		|| rules->inpmap.map[map_y][map_x] == 'd')
		return (1);
	return (0);
}

int	virtual_vertical_colliding(int ray_x, int ray_y, t_rules *rules, int dir)
{
	int	map_x;
	int	map_y;

	if (!dir)
		map_x = ray_x / (int)rules->inpmap.block_width;
	else
		map_x = ray_x / (int)rules->inpmap.block_width - 1;
	map_y = ray_y / (int)rules->inpmap.block_width;
	if (map_x < 0 || map_y < 0
		|| map_x > rules->inpmap.map_height_len[0] - 1
		|| map_y > rules->inpmap.map_height_len[1] - 1)
		return (1);
	if (rules->inpmap.map[map_y][map_x] == '1'
		|| rules->inpmap.map[map_y][map_x] == 'D'
		|| rules->inpmap.map[map_y][map_x] == 'd')
		return (1);
	return (0);
}

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
	data.x = -1;
	data.color = 0x00FFFFFF;
	draw_floor(rules, view);
	draw_ceiling(rules, view);
	while (++data.x < rules->mlx.win_width)
		raycast_calc(&data, rules, view, minimap);
}
