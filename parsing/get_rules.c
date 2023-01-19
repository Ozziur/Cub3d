/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:05:28 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/19 13:40:43 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char *get_path(char *str)
{
    char    *ret;
    int     i;

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
	{
		perror("Error in one of the directions");
		exit(-1);
	}
	path = get_path(buf);
	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_xpm_file_to_image(rules->mlx.mlx, path,
		&image->width, &image->height);
	if (!image)
	{
		perror("Error: can't open xpm file");
		exit(-1);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
		&image->line_length, &image->endian);
	free(path);
	return (image);
}

void	get_color()
{
	
}

void	save_rule(char *buf, t_rules *rules)
{
	if (ft_strncmp(buf, "WE", 2) == 0)
		rules->inpmap.west_wall = get_rule(buf, rules, rules->inpmap.west_wall);
	if (ft_strncmp(buf, "SO", 2) == 0)
		rules->inpmap.south_wall = get_rule(buf, rules, rules->inpmap.west_wall);
	if (ft_strncmp(buf, "NO", 2) == 0)
		rules->inpmap.north_wall = get_rule(buf, rules, rules->inpmap.west_wall);
	if (ft_strncmp(buf, "EA", 2) == 0)
		rules->inpmap.east_wall = get_rule(buf, rules, rules->inpmap.west_wall);
	if (ft_strncmp(buf, "C", 1) == 0)

}