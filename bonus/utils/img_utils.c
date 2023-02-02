/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:10:38 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/02 22:15:26 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	easy_pxl(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}

unsigned int	color_pxl(t_image *tex, int x, int y, t_rules *rules)
{
	if (!(x < 0 || x > rules->mlx.win_width - 1
			|| y < 0 || y > rules->mlx.win_height - 1))
	{
		return (*(unsigned int *)(tex->addr + (4 * (tex->width * y + x))));
	}
	return (0x0);
}

unsigned int	get_color_arr(unsigned char arr[3])
{
	return (((arr[0] & 0xff) << 16) + ((arr[1] & 0xff) << 8) + (arr[2] & 0xff));
}
