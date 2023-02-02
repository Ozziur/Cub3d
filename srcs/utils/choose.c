/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:26:13 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/02 13:38:06 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

t_image	*choose_texture(t_rules *rules, t_bres_data *d)
{
	if (!our_modulo(d->xy2[0], rules->inpmap.block_width)
		&& (d->ray_angle < M_PI_2 || d->ray_angle > 3 * M_PI_2))
		return (rules->inpmap.east_wall);
	else if (!our_modulo(d->xy2[0], rules->inpmap.block_width)
		&& (d->ray_angle >= M_PI_2 && d->ray_angle <= 3 * M_PI_2))
		return (rules->inpmap.west_wall);
	else if (!our_modulo(d->xy2[1], rules->inpmap.block_width)
		&& (d->ray_angle <= M_PI && d->ray_angle >= 0))
		return (rules->inpmap.south_wall);
	else if (!our_modulo(d->xy2[1], rules->inpmap.block_width)
		&& (d->ray_angle > M_PI && d->ray_angle <= 2 * M_PI))
		return (rules->inpmap.north_wall);
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