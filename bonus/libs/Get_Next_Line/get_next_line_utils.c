/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:19:03 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/06 15:32:44 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((unsigned int)ft_strlen_gnl(s) < start)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	str = ft_calloc(((ft_strlen_gnl(s) + 1) - start), sizeof(char));
	if (!str)
		return (NULL);
	while (s[start] != 0 && i < len)
	{
		str[i] = (char)s[start];
		i++;
		start++;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1);
	len += ft_strlen_gnl(s2);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (str);
	while (s1[i] != 0)
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = (char)s2[j];
		i++;
		j++;
	}
	free(s1);
	return (str);
}

int	ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*p;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	p = (char *)ptr;
	while (i < size * count)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
