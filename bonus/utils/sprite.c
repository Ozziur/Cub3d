/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:34:31 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/06 18:12:41 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static void load_sprite(t_image *coll, char *path, t_rules *rules)
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

static void	clear_sprites(t_rules *rules, t_sprite *spr)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		spr[i].x = 0;
		spr[i].y = 0;
		spr[i].mini_x = 0;
		spr[i].mini_y = 0;
		spr[i].dist = 0;
		spr[i].state = 0;
		spr[i].counter = 1;
		spr[i].type = -1;
	}
}

int	save_sprites_supp(t_rules *rules, int i, int ind, int j)
{
	if (rules->inpmap.map[i][j] == 'H' || rules->inpmap.map[i][j] == 'T')
	{
		rules->spr[ind].state = 1;
		rules->spr[ind].mini_x = j;
		rules->spr[ind].mini_y = i;
		rules->spr[ind].counter = 1;
		if (rules->inpmap.map[i][j] == 'T')
			rules->spr[ind++].type = 1;
		else
			rules->spr[ind++].type = 0;
	}
	return (ind);
}

void	save_sprites(t_rules *rules)
{
	int	i;
	int	j;
	int	ind;

	j = -1;
	ind = 0;
	while (++j < rules->inpmap.map_height_len[0])
	{
		i = 0;
		while (rules->inpmap.map[i] && rules->inpmap.map[i][j])
		{
			ind = save_sprites_supp(rules, i, ind, j);
			i++;
		}
	}
}

void init_sprite(t_rules *rules)
{
	load_sprite(rules->skull[0], "textures/64/coll/skull-0.xpm", rules);
	load_sprite(rules->skull[1], "textures/64/coll/skull-1.xpm", rules);
	load_sprite(rules->mage[0], "textures/64/coll/mage-0.xpm", rules);
	load_sprite(rules->mage[1], "textures/64/coll/mage-1.xpm", rules);
	clear_sprites(rules, rules->spr);
	save_sprites(rules);
	
	sort_sprites(rules);
}