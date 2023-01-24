/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:25 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/23 20:27:47 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static char	*get_path(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen(&str[i])));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &str[i], (ft_strlen(&str[i])));
	return (ret);
}

static t_image	*get_rule(char *buf, t_rules *rules, t_image *WindRose)
{
	char	*path;
	t_image	*image;

	if (WindRose != NULL)
		ft_exit("Error in one of the directions");
	path = get_path(buf);
	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_xpm_file_to_image(rules->mlx.mlx, path,
			&image->width, &image->height);
	if (!image->img)
		ft_exit("Error: can't open xpm file");
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
	free(path);
	return (image);
}

static int	get_color(char *str, unsigned char rgb[3])
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (str[i] && !ft_isdigit(str[i]))
	{
		i++;
		if (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		{	
			temp = ft_atoi(&str[i]);
			if (temp > 255 || temp < 0)
				ft_exit("Color not valid");
			rgb[j++] = (unsigned char)temp;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
	}
	if (j != 3)
		ft_exit("Invalid color format");
	return (1);
}

void	save_rule(char *buf, t_rules *rules)
{
	if (ft_strncmp(buf, "WE", 2) == 0)
		rules->inpmap.west_wall = get_rule(buf, rules, rules->inpmap.west_wall);
	else if (ft_strncmp(buf, "SO", 2) == 0)
		rules->inpmap.south_wall = get_rule(buf, rules, rules->inpmap.south_wall);
	else if (ft_strncmp(buf, "NO", 2) == 0)
		rules->inpmap.north_wall = get_rule(buf, rules, rules->inpmap.north_wall);
	else if (ft_strncmp(buf, "EA", 2) == 0)
		rules->inpmap.east_wall = get_rule(buf, rules, rules->inpmap.east_wall);
	else if (ft_strncmp(buf, "C", 1) == 0)
		rules->inpmap.ceiling = get_color(buf, rules->inpmap.c_color);
	else if (ft_strncmp(buf, "F", 1) == 0)
		rules->inpmap.floor = get_color(buf, rules->inpmap.f_color);
}
