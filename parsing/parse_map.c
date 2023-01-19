/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:29:23 by anovelli          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/19 14:12:05 by anovelli         ###   ########.fr       */
=======
/*   Updated: 2023/01/19 14:44:48 by mruizzo          ###   ########.fr       */
>>>>>>> e40b01585934820db43a411ed9a652ba9c5575af
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	rules_status(t_rules *rules)
{
	if (!rules->inpmap.north_wall || !rules->inpmap.south_wall
		|| !rules->inpmap.east_wall || !rules->inpmap.west_wall
		|| !rules->inpmap.f_color || !rules->inpmap.c_color)
		return (0);
	return (1);
}

void	ft_parsing(char *input, t_rules *rules)
{
	int			fd;
	char		*buf;

	fd = open(input, 'r');
	if (fd < 0)
		exit(-1);//aggiungere stampa
	buf = get_next_line(fd);
	while (buf && !rules_status(rules))
	{
		// rules->line_offset++; chiedere delucidazioni a giorgio o davide
		save_rule(buf, rules);
		free(buf);
		buf = get_next_line(fd);
	}
	if (!rules_status(rules))
		exit(-1);//aggiungere stampa
	
	/*
	while (!is_map(tmp))
	{
		rules->line_offset++;
		insert_rule(tmp, rules);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	*/
}