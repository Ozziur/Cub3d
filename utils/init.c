/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:56 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 15:54:41 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void init_rules(t_rules *rules)
{
	rules->mlx.win_width = 1024;
	rules->mlx.win_height = 768;
}



void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx)
		exit(-1);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height, "Cub3d");
}