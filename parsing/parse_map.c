/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:29:23 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/19 19:42:38 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static int	rules_status(t_rules *rules)
{
	if (!rules->inpmap.north_wall || !rules->inpmap.south_wall
		|| !rules->inpmap.east_wall || !rules->inpmap.west_wall
		|| !rules->inpmap.floor || !rules->inpmap.ceiling)
		return (0);
	return (1);
}

static int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != ' ' && line[i] != '\n')
			return (0);
	}
	return (1);
}

void save_len(int fd, t_rules *rules)
{
	char	*buf;

	rules->inpmap.map_height_len[0] = 0;
	rules->inpmap.map_height_len[1] = 1;
	buf = get_next_line(fd);
	while (buf && is_map(buf) == 0)
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

static void	write_matrix(t_rules *rules, int fd)
{
	int		j;
	int 	i;
	char	*buf;

	i = 0;
	buf = get_next_line(fd);
	while (i++ < rules->inpmap.line_offset++)
	{
		free(buf);
		buf = get_next_line(fd);
	}
	i = 0;
	while (buf)
	{
		j = ft_strlen(buf);
		if (!is_map(buf))
		{
			perror("not valid map");
			exit(1);
		}
		ft_strlcpy(rules->inpmap.map[i], buf, j-- + 1);
		while (j < rules->inpmap.map_height_len[0])
			rules->inpmap.map[i][j++] = ' ';
		rules->inpmap.map[i][j++] = '\0';
		i++;
		free(buf);
		buf = get_next_line(fd);
	}
}

void	save_map(int fd, t_rules *rules, char *file)
{
	int i;

	save_len(fd, rules);
	rules->inpmap.map = malloc(sizeof(char *) * rules->inpmap.map_height_len[1] + 1);
	//protezione
	i = 0;
	while (i < rules->inpmap.map_height_len[1])
	{
		rules->inpmap.map[i++] = malloc(sizeof(char *) * rules->inpmap.map_height_len[0] + 1);
		//protezione
	}
	fd = open(file, 'r');
	rules->inpmap.map[i]= NULL;
	write_matrix(rules, fd);
}

void	ft_parsing(char *input, t_rules *rules)
{
	int			fd;
	char		*buf;

	fd = open(input, 'r');
	if (fd < 0)
	{
		perror("can't open the file");
		exit(49);//aggiungere stampa
	}
	buf = get_next_line(fd);
	while (buf && !rules_status(rules))
	{
		rules->inpmap.line_offset++;
		save_rule(buf, rules);
		free(buf);
		buf = get_next_line(fd);
	}
	if (!rules_status(rules))
	{
		/*
			inserire la letture di rules
		*/
		printf("älice si droga");
			exit(-1);//aggiungere stampa
	}
	while (ft_strncmp("\n", buf, 1))
	{
		free(buf);
		buf = get_next_line(fd);
	}
	//save_map(fd, rules, input);
	free(buf);
	close(fd);
}