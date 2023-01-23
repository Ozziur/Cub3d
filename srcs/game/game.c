/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:09:30 by mruizzo           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/23 15:39:42 by anovelli         ###   ########.fr       */
=======
/*   Updated: 2023/01/23 16:04:18 by mruizzo          ###   ########.fr       */
>>>>>>> b3fc95bda86c883c3b18d03d243c29316c19f67b
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	raycast(t_rules *rules, t_image	*view, t_image	*minimap)
{
	
}

void	game(t_rules *rules)
{
	t_image	view;
	t_image	minimap;

	init_img(rules, &view, rules->mlx.win_width, rules->mlx.win_height);
	init_img(rules, &minimap,
			rules->inpmap.map_height_len[0] * rules->inpmap.mini_block_width,
			rules->inpmap.map_height_len[1] * rules->inpmap.mini_block_width);
	raycast(rules, &view, &minimap);
	mlx_put_image_to_window(rules->mlx.mlx, rules->mlx.mlx_win, view.img, 0, 0);
}