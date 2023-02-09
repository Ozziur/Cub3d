/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:54:33 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/09 12:11:19 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	valid_zero(char c)
{
	if (c != 'N' && c != 'E' && c != 'S' && c != 'W'
		&& c != '1' && c != '0' && c != 'D' && c != 'H'
		&& c != 'T' && c != '*')
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

int	rules_status(t_rules *rules)
{
	if (!rules->inpmap.north_wall || !rules->inpmap.south_wall
		|| !rules->inpmap.east_wall || !rules->inpmap.west_wall
		|| !rules->inpmap.floor || !rules->inpmap.ceiling)
		return (0);
	return (1);
}

int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != ' ' && line[i] != '\n'
			&& line [i] != 'D' && line [i] != 'T' && line [i] != 'H'
			&& line [i] != '*')
			ft_exit("Map is invalid\n");
	}
	return (1);
}

void	save_len(int fd, t_rules *rules)
{
	char	*buf;

	rules->inpmap.map_height_len[0] = 0;
	rules->inpmap.map_height_len[1] = 1;
	buf = get_next_line(fd);
	while (buf && is_map(buf))
	{
		if (ft_strlen(buf) > rules->inpmap.map_height_len[0])
			rules->inpmap.map_height_len[0] = ft_strlen(buf);
		rules->inpmap.map_height_len[1]++;
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	close(fd);
}
