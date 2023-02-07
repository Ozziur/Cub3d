/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:18:58 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/07 14:28:17 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static int	one_player(t_rules *rules)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < rules->inpmap.map_height_len[1])
	{
		j = 0;
		while (j < rules->inpmap.map_height_len[0])
		{
			if (rules->inpmap.map[i][j] == 'N'
			|| rules->inpmap.map[i][j] == 'S'
			|| rules->inpmap.map[i][j] == 'E'
			|| rules->inpmap.map[i][j] == 'W')
			flag++;
			j++;
		}
	i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}

static int	one_coll(t_rules *rules)
{
	int	i;
	int	j;
	int	flag_h;
	int	flag_t;

	i = 0;
	flag_h = 0;
	flag_t = 0;
	while (i < rules->inpmap.map_height_len[1])
	{
		j = 0;
		while (j < rules->inpmap.map_height_len[0])
		{
			if (rules->inpmap.map[i][j] == 'H')
				flag_h++;
			else if (rules->inpmap.map[i][j] == 'T')
				flag_t++;
			j++;
		}
	i++;
	}
	if (flag_t != 1 || flag_h != 1)
		return (0);
	return (1);
}

static int	check_player(t_rules *rules, int i, int j)
{
	if (((rules->inpmap.map[i + 1][j] != '0'
			&& rules->inpmap.map[i + 1][j] != '1')
	&& (rules->inpmap.map[i - 1][j] != '0'
		&& rules->inpmap.map[i - 1][j] != '1')
	&& (rules->inpmap.map[i][j + 1] != '0'
		&& rules->inpmap.map[i][j + 1] != '1')
	&& (rules->inpmap.map[i][j - 1] != '0'
		&& rules->inpmap.map[i][j - 1] != '1'))
	|| !one_player(rules) || !one_coll(rules))
		return (0);
	return (1);
}

int	check_height(t_rules *rules)
{
	if (ft_strchr(rules->inpmap.map[rules->inpmap.map_height_len[1] - 1],
			'0')
		|| ft_strchr(rules->inpmap.map[rules->inpmap.map_height_len[1] - 1],
			'D')
		|| ft_strchr(rules->inpmap.map[rules->inpmap.map_height_len[1] - 1],
			'T')
		|| ft_strchr(rules->inpmap.map[rules->inpmap.map_height_len[1] - 1],
			'H'))
		return (1);
	return (0);
}

void	ultimate_check(t_rules *rules)
{
	int	i;
	int	j;

	i = 0;
	while (i < rules->inpmap.map_height_len[1] - 1)
	{
		if (ft_strchr(rules->inpmap.map[0], '0')
			|| ft_strchr(rules->inpmap.map[0], 'D')
			|| ft_strchr(rules->inpmap.map[0], 'H')
			|| ft_strchr(rules->inpmap.map[0], 'T'))
			ft_exit("utlimate_check: map not valid");
		j = 0;
		while (j < rules->inpmap.map_height_len[0])
		{
			if (j == rules->inpmap.map_height_len[0])
				if (ft_strchr(rules->inpmap.map[i], '0')
					|| ft_strchr(rules->inpmap.map[i], 'D')
					|| ft_strchr(rules->inpmap.map[i], 'T')
					|| ft_strchr(rules->inpmap.map[i], 'H'))
					ft_exit("utlimate_check1: map not valid");
			if (rules->inpmap.map[i][j] == '0'
				|| rules->inpmap.map[i][j] == 'D'
				|| rules->inpmap.map[i][j] == 'T'
				|| rules->inpmap.map[i][j] == 'H')
				if (!check_zero(rules, i, j) || !check_player(rules, i, j))
					ft_exit("utlimate_check2: map not valid");
			j++;
		}
		i++;
	}
	if (check_height(rules))
		ft_exit("utlimate_check3: map not valid");
	find_player(rules);
}
