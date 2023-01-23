/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:18:58 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/23 20:26:22 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	valid_zero(char c)
{
	if (c != 'N' && c != 'E' && c != 'S' && c != 'W' && c != '1' && c != '0')
		return (0);
	return (1);
}

int	check_zero(t_rules *rules, int i, int j)
{
	if (valid_zero(rules->inpmap.map[i + 1][j]) == 0
	|| valid_zero(rules->inpmap.map[i - 1][j]) == 0
	|| valid_zero(rules->inpmap.map[i][j + 1]) == 0
	|| valid_zero(rules->inpmap.map[i][j - 1]) == 0)
		return (0);
	return (1);
}

int	one_player(t_rules *rules)
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

int	check_player(t_rules *rules, int i, int j)
{
	if (((rules->inpmap.map[i + 1][j] != '0' && rules->inpmap.map[i + 1][j] != '1')
	&& (rules->inpmap.map[i - 1][j] != '0' && rules->inpmap.map[i - 1][j] != '1')
	&& (rules->inpmap.map[i][j + 1] != '0' && rules->inpmap.map[i][j + 1] != '1')
	&& (rules->inpmap.map[i][j - 1] != '0' && rules->inpmap.map[i][j - 1] != '1'))
	|| !one_player(rules))
		return (0);
	return (1);
}

void	ultimate_check(t_rules *rules)
{
	int	i;
	int	j;

	i = 0;
	while (i < rules->inpmap.map_height_len[1])
	{
		j = 0;
		while (j < rules->inpmap.map_height_len[0])
		{
			if (j == rules->inpmap.map_height_len[0])
				if (ft_strchr_gnl(rules->inpmap.map[i], '0'))
					ft_exit("utlimate_check1: map not valid");
				if (rules->inpmap.map[i][j] == '0')
					if (!check_zero(rules, i, j) || !check_player(rules, i, j))
						ft_exit("utlimate_check2: map not valid");
			j++;
		}
		i++;
	}
}
