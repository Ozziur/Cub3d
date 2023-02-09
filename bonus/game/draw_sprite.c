/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:19:59 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/09 15:06:10 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	draw_sprite_col(t_rules *rules, t_draw_coord *info,
	t_image *view, double trans_y)
{
	if (trans_y > 0 && info->start_x > 0 && info->start_x < rules->mlx.win_width
		&& trans_y < rules->dist_array[(int)info->start_x])
	{
		info->start_y = info->bench_y;
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

static void	define_sprite_info_deep(t_rules *rules, t_draw_coord *info,
	int var[2], double trans_y)
{
	info->bench_y = info->start_y;
	if (info->start_y < 0)
		info->start_y = 0;
	info->end_y = rules->mlx.win_height / 2 + info->height / 2;
	if (var[0])
		info->end_y += var[0];
	if (info->end_y > rules->mlx.win_height)
		info->end_y = rules->mlx.win_height;
	info->width = get_abs_double((rules->mlx.win_height / trans_y))
		* (info->sprite->width);
	info->start_x = -info->width / 2 + var[1];
	info->bench_x = info->start_x;
	if (info->start_x < 0)
		info->start_x = 0;
	info->end_x = info->width / 2 + var[1];
	if (info->end_x > rules->mlx.win_width)
		info->end_x = rules->mlx.win_width;
}

t_draw_coord	*define_sprite_info(t_rules *rules, double trans_y,
	int s_x, int i)
{
	t_draw_coord	*info;
	int				var[2];

	var[0] = 0;
	var[1] = s_x;
	info = malloc(sizeof(t_draw_coord));
	if (!info)
		ft_exit("Malloc error");
	info->sprite = rules->animations[rules->sort_spr[i]->type + flag()];
	if (info->sprite == NULL)
	{
		free(info);
		return (0);
	}
	info->height = (rules->mlx.win_height / trans_y)
		* (info->sprite->height);
	if (rules->sort_spr[i]->type == 0)
		var[0] = info->height / 3;
	info->start_y = rules->mlx.win_height / 2 - info->height / 2;
	if (var[0])
		info->start_y += var[0];
	define_sprite_info_deep(rules, info, var, trans_y);
	return (info);
}

void	draw_sprites_2(t_rules *rules, int num[2], double var[5])
{
	var[0] = rules->sort_spr[num[0]]->x - rules->player.x;
	if (!var[0])
		var[0] = 1;
	var[1] = rules->sort_spr[num[0]]->y - rules->player.y;
	var[2] = 1.0 / (rules->player.plane_x * rules->player.d_y
			- rules->player.d_x * rules->player.plane_y);
	var[3] = var[2] * (rules->player.d_y * var[0]
			- rules->player.d_x * var[1])
		* (854 * 2.6 / (float)rules->mlx.win_width);
	var[4] = var[2] * (-rules->player.plane_y
			* var[0] + rules->player.plane_x * var[1]);
	num[1] = (int)((rules->mlx.win_width / 2) * (1 + var[3] / var[4]));
}

void draw_sprite_utils(t_rules *rules, t_draw_coord	*info, t_image *view, double *var)
{
						info->t_x = (int)((info->start_x - info->bench_x)
							* info->sprite->width / info->width);
					draw_sprite_col(rules, info, view, var[4]);
					info->start_x++;
}

void	draw_sprites(t_rules *rules, t_image *view)
{
	t_draw_coord	*info;
	double			var[5];
	int				num[2];

	reload_sprites(rules);
	num[0] = 0;
	while (num[0] < rules->n_sprites)
	{
		if (rules->sort_spr[num[0]]->state
			&& rules->sort_spr[num[0]]->dist > rules->inpmap.block_width / 2)
		{
			draw_sprites_2(rules, num, var);
			info = define_sprite_info(rules, var[4], num[1], num[0]);
			if (info != 0)
			{
				while (info->start_x < info->end_x)
						draw_sprite_utils(rules, info, view, var);
				free(info);
			}
		}
		num[0]++;
	}
}
