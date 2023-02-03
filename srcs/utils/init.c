/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:56 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/03 18:41:21 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static void	inpmap_init(t_rules *rules)
{
	rules->inpmap.north_wall = NULL;
	rules->inpmap.south_wall = NULL;
	rules->inpmap.east_wall = NULL;
	rules->inpmap.west_wall = NULL;
	rules->inpmap.ceiling = 0;
	rules->inpmap.floor = 0;
	rules->inpmap.line_offset = 0;
	rules->inpmap.block_width = 64;
	rules->inpmap.mini_block_width = rules->inpmap.block_width / 4;
}

static void	init_keys(t_rules *rules)
{
	rules->keys.w_pressed = 0;
	rules->keys.a_pressed = 0;
	rules->keys.s_pressed = 0;
	rules->keys.d_pressed = 0;
	rules->keys.l_pressed = 0;
	rules->keys.r_pressed = 0;
	rules->keys.shift_pressed = 0;
}

void	init_rules(t_rules *rules)
{
	rules->mlx.win_width = 1024;
	rules->mlx.win_height = 768;
	rules->n_frames = 1;
	inpmap_init(rules);
	init_keys(rules);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx)
		exit(-1);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_width,
			mlx->win_height, "Cub3d");
}

void	init_img(t_rules *rules, t_image *img, int w, int h)
{
	img->img = mlx_new_image(rules->mlx.mlx, w, h);
	if (!img->img)
		ft_exit("Error initializing image");
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}
