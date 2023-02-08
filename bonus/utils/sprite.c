/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:34:31 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/08 12:54:35 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	init_xpm_img(t_rules *rules, t_image **img, char *path)
{
	(*img) = malloc(sizeof(t_image));
	if (!(*img))
		ft_exit("Malloc error");
	(*img)->img = mlx_xpm_file_to_image(rules->mlx.mlx, path,
			&(*img)->width, &(*img)->height);
	if (!(*img)->img)
		ft_exit("Error initializing image");
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_length, &(*img)->endian);
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
			rules->spr[ind++].type = 0;
		else
			rules->spr[ind++].type = 2;
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

int	count_sprites(t_inputmap map)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	j = -1;
	while (++j < map.map_height_len[0])
	{
		i = 0;
		while (map.map[i] && map.map[i][j])
		{
			if (map.map[i][j] == 'T' || map.map[i][j] == 'H')
				ret++;
			i++;
		}
	}
	return (ret);
}

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
	// update_sprites(rules);
	clear_sorted_sprites(rules, rules->sort_spr);
	free(rules->sort_spr);
	sort_sprites(rules);
}