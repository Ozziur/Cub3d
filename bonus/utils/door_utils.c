/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:08:37 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/03 18:52:10 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

t_image	*init_door(int index, t_rules *rules)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	if (index == 0)
	{
		image->img = mlx_xpm_file_to_image(rules->mlx.mlx,
				"./textures/64/door-close.xpm", &image->width, &image->height);
		if (!image->img)
			ft_exit("Error: can't open xpm file");
		image->addr = mlx_get_data_addr(image->img, &image->bpp,
				&image->line_length, &image->endian);
		return (image);
	}
	else
	{
		image->img = mlx_xpm_file_to_image(rules->mlx.mlx,
				"./textures/64/door-open.xpm", &image->width, &image->height);
		if (!image->img)
			ft_exit("Error: can't open xpm file");
		image->addr = mlx_get_data_addr(image->img, &image->bpp,
				&image->line_length, &image->endian);
		return (image);
	}
}
