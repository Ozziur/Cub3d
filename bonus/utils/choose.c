/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:26:13 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/08 13:43:13 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static t_image	*ret_tex(int x, int y, t_rules *rules, t_image *wall)
{
	if (rules->inpmap.map[y][x] == 'D')
		return (rules->inpmap.door_image[0]);
	else if (rules->inpmap.map[y][x] == 'd')
		return (rules->inpmap.door_image[1]);
	else if (rules->inpmap.map[y][x] == '*')
	{
		if (rules->flag_hat && !rules->flag_skull)
			return (rules->inpmap.exit[2]);
		else if (rules->flag_skull && !rules->flag_hat)
			return (rules->inpmap.exit[3]);
		else if (rules->flag_hat && rules->flag_skull)
			return (rules->inpmap.exit[1]);
		else
			return (rules->inpmap.exit[0]);
	}
	else
		return (wall);
}

t_image	*choose_texture(t_rules *rules, t_bres_data *d)
{
	if (!our_modulo(d->xy2[0], rules->inpmap.block_width)
		&& (d->ray_angle < M_PI_2 || d->ray_angle > 3 * M_PI_2))
		return (ret_tex((int)(d->xy2[0] / rules->inpmap.block_width),
			(int)(d->xy2[1] / rules->inpmap.block_width),
				rules, rules->inpmap.east_wall));
	else if (!our_modulo(d->xy2[0], rules->inpmap.block_width)
		&& (d->ray_angle >= M_PI_2 && d->ray_angle <= 3 * M_PI_2))
		return (ret_tex((int)(d->xy2[0] / rules->inpmap.block_width) - 1,
			(int)(d->xy2[1] / rules->inpmap.block_width),
				rules, rules->inpmap.west_wall));
	else if (!our_modulo(d->xy2[1], rules->inpmap.block_width)
		&& (d->ray_angle <= M_PI && d->ray_angle >= 0))
		return (ret_tex((int)(d->xy2[0] / rules->inpmap.block_width),
			(int)(d->xy2[1] / rules->inpmap.block_width) - 1,
				rules, rules->inpmap.south_wall));
	else if (!our_modulo(d->xy2[1], rules->inpmap.block_width)
		&& (d->ray_angle > M_PI && d->ray_angle <= 2 * M_PI))
		return (ret_tex((int)(d->xy2[0] / rules->inpmap.block_width),
			(int)(d->xy2[1] / rules->inpmap.block_width),
				rules, rules->inpmap.north_wall));
	else
		ft_exit("fra non lo so facci passare pls");
	return (NULL);
}

int	choose_x(t_draw_info *info, float ref, t_rules *rules)
{
	return (our_modulo(ref, rules->inpmap.block_width) * info->tex->width
		/ rules->inpmap.block_width);
}

int	choose_y(int var, t_draw_info *info)
{
	return ((var - info->off) * info->tex->width / info->l_h);
}
