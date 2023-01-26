/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:19:48 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/26 13:49:14 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/get_next_line.h"

char	*get_line(char *save, int fd)
{
	int		count;
	char	*buffer;

	count = 1;
	if (!save)
		save = ft_calloc(1, 1);
	while (ft_strchr_gnl(save, '\n') == -1 && count > 0)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0 || (count == 0 && save[0] == 0))
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		save = ft_strjoin_gnl(save, buffer);
		free(buffer);
	}
	return (save);
}

char	*ft_save(char *save, char *str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
		i++;
	if (save[i] == 0)
	{
		free(save);
		return (NULL);
	}
	tmp = ft_substr(save, i, ft_strlen_gnl(save) - i);
	free(save);
	save = ft_substr(tmp, 0, ft_strlen_gnl(tmp));
	free (tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*str_rtr;
	size_t		i;

	i = 0;
	if (fd < 0 || fd > 1024)
		return (NULL);
	line[fd] = get_line(line [fd], fd);
	if (!line[fd])
		return (NULL);
	while (line[fd][i] != '\n' && line[fd][i])
		i++;
	str_rtr = ft_substr(line[fd], 0, i + 1);
	line[fd] = ft_save(line[fd], str_rtr);
	return (str_rtr);
}
