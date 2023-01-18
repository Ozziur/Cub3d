/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:56 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 19:29:34 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static void inpmap_init(t_rules *rules)
{
	rules->inpmap.c_color = NULL;
	rules->inpmap.f_color = NULL;
	rules->inpmap.north_wall = NULL;
	rules->inpmap.south_wall = NULL;
	rules->inpmap.east_wall = NULL;
	rules->inpmap.west_wall = NULL;
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