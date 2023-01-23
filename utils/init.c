/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:56 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/23 16:30:23 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static void inpmap_init(t_rules *rules)
{
	rules->inpmap.north_wall = NULL;
	rules->inpmap.south_wall = NULL;
	rules->inpmap.east_wall = NULL;
	rules->inpmap.west_wall = NULL;
	rules->inpmap.ceiling = 0;
	rules->inpmap.floor = 0;
	rules->inpmap.line_offset = 0;
}

void init_rules(t_rules *rules)
{
	rules->mlx.win_width = 1024;
	rules->mlx.win_height = 768;
	inpmap_init(rules);
}

void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx)
		exit(-1);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height, "Cub3d");
}

void	init_img(t_rules *rules, t_image *img, int w, int h)
{
	img->img = mlx_new_image(rules->mlx.mlx, w, h);
	if (!img->img)
		ft_exit("Error initializing image");
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}