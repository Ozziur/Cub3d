/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:34:31 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/06 15:50:12 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static void load_sprite(t_image *coll, char *path)
{
	coll = malloc(sizeof(t_image));
	if (!coll)
		ft_exit("malloc error");
	coll->img = mlx_xpm_file_to_image(rules->mlx.mlx,
			path, &coll->width, &coll->height);
	if (!coll->img)
		ft_exit("Error: can't open xpm file");
	coll->addr = mlx_get_data_addr(coll->img, &coll->bpp,
			&coll->line_length, &coll->endian);
}

void init_sprite(t_rules *rules)
{
	load_sprite(rules->skull[0], "textures/64/coll/skull-0.xpm");
	load_sprite(rules->skull[1], "textures/64/coll/skull-1.xpm");
}