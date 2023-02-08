/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:34:31 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/08 17:50:34 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	init_sprite(t_rules *rules)
{
	rules->animations = malloc(sizeof(t_image *) * 6);
	if (!rules->animations)
		ft_exit("Malloc error");
	init_xpm_img(rules, &rules->animations[0], "textures/64/coll/skull-0.xpm");
	init_xpm_img(rules, &rules->animations[1], "textures/64/coll/skull-1.xpm");
	init_xpm_img(rules, &rules->animations[2], "textures/64/coll/mage-0.xpm");
	init_xpm_img(rules, &rules->animations[3], "textures/64/coll/mage-1.xpm");
	rules->animations[5] = NULL;
	rules->n_sprites = count_sprites(rules->inpmap);
	clear_sprites(rules, rules->spr);
	save_sprites(rules);
	sort_sprites(rules);
}

void	clear_sorted_sprites(t_rules *rules, t_sprite **sort_spr)
{
	int	i;

	i = -1;
	while (++i < 2)
		sort_spr[i] = NULL;
	(void) rules;
}

double	get_sprite_dist(t_rules *rules, t_sprite *spr)
{
	double	spr_xy[2];

	spr_xy[0] = spr->mini_x * rules->inpmap.block_width
		+ rules->inpmap.block_width / 2;
	spr_xy[1] = spr->mini_y * rules->inpmap.block_width
		+ rules->inpmap.block_width / 2;
	spr->x = spr_xy[0];
	spr->y = spr_xy[1];
	return (final_length_double(rules->player.x, rules->player.y, spr_xy));
}

void	update_sprites(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		rules->spr[i].dist = get_sprite_dist(rules, &rules->spr[i]);
		if (rules->spr[i].type)
		{
			rules->spr[i].counter++;
		}
	}
}

void	reload_sprites(t_rules *rules)
{
	update_sprites(rules);
	clear_sorted_sprites(rules, rules->sort_spr);
	free(rules->sort_spr);
	sort_sprites(rules);
}
