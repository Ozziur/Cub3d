/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:06:20 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/09 12:11:28 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	check_long(t_rules *rules, int i, int j)
{
	if (j == rules->inpmap.map_height_len[0])
		if (ft_strchr(rules->inpmap.map[i], '0')
			|| ft_strchr(rules->inpmap.map[i], 'D')
			|| ft_strchr(rules->inpmap.map[i], 'T')
			|| ft_strchr(rules->inpmap.map[i], 'H'))
			return (0);
	if (rules->inpmap.map[i][j] == '0'
		|| rules->inpmap.map[i][j] == 'D'
		|| rules->inpmap.map[i][j] == 'T'
		|| rules->inpmap.map[i][j] == 'H')
		if (!check_zero(rules, i, j) || !check_player(rules, i, j))
			return (0);
	return (1);
}
