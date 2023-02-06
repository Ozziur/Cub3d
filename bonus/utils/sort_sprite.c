/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:30:43 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/06 18:03:55 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static double	get_sprite_dist(t_rules *rules, t_sprite *spr)
{
	double	spr_xy[2];

	spr_xy[0] = spr->mini_x * rules->inpmap.block_width
		+ rules->inpmap.block_width / 2;
	spr_xy[1] = spr->mini_y * rules->inpmap.block_width
		+ rules->inpmap.block_width / 2;
	spr->x = spr_xy[0];
	spr->y = spr_xy[1];
	return (final_length_double(rules->player.x, rules->player.y, spr_xy));
}

static void	fill_sort_spr(t_rules *rules, int *arr)
{
	int	i;

	i = -1;
	while (++i < 2)
		rules->sort_spr[i] = &rules->spr[arr[i] - 1];
}

static void	move_one_forward(int *arr, int i, int limit)
{
	while (i > limit)
	{
		arr[i] = arr[i - 1];
		i--;
	}
}

static int	*find_indexes(t_rules *rules)
{
	int		*ret;
	int		i;
	int		i2;

	ret = malloc(sizeof(int) * (2 + 1));
	if (!ret)
		ft_exit("Malloc error");
	i = 0;
	while (i < 2)
		ret[i++] = 0;
	i = 0;
	while (i < 2)
	{
		rules->spr[i].dist = get_sprite_dist(rules, &rules->spr[i]);
		i2 = 0;
		while (ret[i2] && rules->spr[i].dist < rules->spr[ret[i2] - 1].dist
			&& i2 < 2)
			i2++;
		move_one_forward(ret, 2, i2);
		ret[i2] = i + 1;
		i++;
	}
	return (ret);
}

void	sort_sprites(t_rules *rules)
{
	int	*sorted_index;

	sorted_index = find_indexes(rules);
	rules->sort_spr = malloc(sizeof(t_sprite *) * 2);
	if (!rules->sort_spr)
		ft_exit("Malloc error");
	fill_sort_spr(rules, sorted_index);
	free(sorted_index);
}
