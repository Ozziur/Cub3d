/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:42:27 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/07 14:14:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static int	define_ver_ray_and_offset(t_rules *rules, t_ray *ray,
	double n_tan, float xy[2])
{
	if (ray->angle < M_PI / 2 || ray->angle > 3 * M_PI / 2)
	{
		ray->x = xy[0] + (rules->inpmap.block_width - our_modulo(xy[0],
					rules->inpmap.block_width));
		ray->y = xy[1] - (xy[0] - ray->x) * n_tan;
		ray->xyoff[0] = rules->inpmap.block_width;
		ray->xyoff[1] = ray->xyoff[0] * n_tan;
		return (0);
	}
	else if (ray->angle >= M_PI / 2 && ray->angle <= 3 * M_PI / 2)
	{
		ray->x = xy[0] - our_modulo(xy[0], rules->inpmap.block_width);
		ray->y = xy[1] - (xy[0] - ray->x) * n_tan;
		ray->xyoff[0] = -rules->inpmap.block_width;
		ray->xyoff[1] = ray->xyoff[0] * n_tan;
		return (1);
	}
	return (0);
}

static void	vertical_lines_check(double angle,	t_rules *rules, float ret[3])
{
	t_ray	ray;
	double	n_tan;
	float	xy[2];

	xy[0] = rules->player.x;
	xy[1] = rules->player.y;
	ray.angle = angle;
	n_tan = -tan(ray.angle);
	ret[2] = define_ver_ray_and_offset(rules, &ray, n_tan, xy);
	while (!virtual_vertical_colliding(ray.x, ray.y, rules, ret[2])
		&& ray.angle != (double) M_PI / 2
		&& ray.angle != (double)(3 * M_PI / 2) && ray.x != INT_MAX)
	{
		ray.x += ray.xyoff[0];
		ray.y += ray.xyoff[1];
	}
	ret[0] = ray.x;
	ret[1] = ray.y;
}

static int	define_hor_ray_and_offset(t_rules *rules, t_ray *ray,
	double co_tan, float xy[2])
{
	if (ray->angle < M_PI)
	{
		ray->y = xy[1] - (rules->inpmap.block_width - (rules->inpmap.block_width
					- our_modulo(xy[1], rules->inpmap.block_width)));
		ray->x = (xy[1] - ray->y) * co_tan + xy[0];
		ray->xyoff[1] = -rules->inpmap.block_width;
		ray->xyoff[0] = -ray->xyoff[1] * co_tan;
		return (0);
	}
	else
	{
		ray->y = xy[1] + (rules->inpmap.block_width - our_modulo(xy[1],
					rules->inpmap.block_width));
		ray->x = (xy[1] - ray->y) * co_tan + xy[0];
		ray->xyoff[1] = rules->inpmap.block_width;
		ray->xyoff[0] = -ray->xyoff[1] * co_tan;
		return (1);
	}
}

static void	horizontal_lines_check(double angle, t_rules *rules, float ret[3])
{
	t_ray	ray;
	double	co_tan;
	float	xy[2];

	xy[0] = rules->player.x;
	xy[1] = rules->player.y;
	ray.angle = angle;
	co_tan = 1 / tan(ray.angle);
	ret[2] = define_hor_ray_and_offset(rules, &ray, co_tan, xy);
	while (!virtual_horizontal_colliding(ray.x, ray.y, rules, ret[2])
		&& ray.angle != 0 && ray.angle != (double)M_PI && ray.x != INT_MAX)
	{
		ray.x += ray.xyoff[0];
		ray.y += ray.xyoff[1];
	}
	ret[0] = ray.x;
	ret[1] = ray.y;
}

void	raycast_calc(t_bres_data *data, t_rules *rules,
			t_image *view, t_image *minimap)
{
	float	h_pts[3];
	float	v_pts[3];

	horizontal_lines_check(data->ray_angle, rules, h_pts);
	vertical_lines_check(data->ray_angle, rules, v_pts);
	data->xy[0] = rules->player.x;
	data->xy[1] = rules->player.y;
	if (final_length(rules->player.x, rules->player.y, v_pts) == INT_MAX
		|| final_length(rules->player.x, rules->player.y, h_pts)
		< final_length(rules->player.x, rules->player.y, v_pts))
	{
		data->xy2[0] = h_pts[0];
		data->xy2[1] = h_pts[1];
		bresenham(data, minimap, view, rules);
	}
	else
	{
		data->xy2[0] = v_pts[0];
		data->xy2[1] = v_pts[1];
		bresenham(data, minimap, view, rules);
	}
	data->ray_angle = decrement_angle(data->ray_angle, 1);
}
