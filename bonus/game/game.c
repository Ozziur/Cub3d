/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:09:30 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/09 15:53:42 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	minimap2d(t_rules *rules, t_image *minimap);

void	game(t_rules *rules)
{
	t_image	view;
	t_image	minimap;


	debug ("game1\n");
	init_img(rules, &view, rules->mlx.win_width, rules->mlx.win_height);
	init_img(rules, &minimap,
		rules->inpmap.map_height_len[0] * rules->inpmap.mini_block_width,
		rules->inpmap.map_height_len[1] * rules->inpmap.mini_block_width);
	minimap2d(rules, &minimap);

	debug ("game2\n");
	raycast(rules, &view, &minimap);
	debug ("game3\n");
	draw_sprites(rules, &view);

	mlx_put_image_to_window(rules->mlx.mlx, rules->mlx.mlx_win, view.img, 0, 0);
	mlx_put_image_to_window(rules->mlx.mlx, rules->mlx.mlx_win,
		minimap.img, 0, 0);
	mlx_destroy_image(rules->mlx.mlx, view.img);
	mlx_destroy_image(rules->mlx.mlx, minimap.img);
}
