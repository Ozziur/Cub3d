/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:46:31 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/08 15:59:01 by anovelli         ###   ########.fr       */
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

void	clear_sprites(t_rules *rules, t_sprite *spr)
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
