/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:11 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/09 21:15:15 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

int	arg_check(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "Error: wrong arguments\n", 23);
		return (0);
	}
	else if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		write(1, "Error: invalid file extention\n", 30);
		return (0);
	}
	return (1);
}

char	*ft_strchr_start(const char *s, int c, char start)
{
	while (*s != start)
		s++;
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

void	easter_egg(t_rules *rules)
{
	int	i;
	int	j;

	i = 0;
	while (rules->inpmap.map[i])
	{
		j = 0;
		while (rules->inpmap.map[i][j])
		{
			if (rules->inpmap.map[i][j] == 'N')
			{
				if (ft_strchr_start(rules->inpmap.map[i],
						'H', rules->inpmap.map[i][j])
				|| ft_strchr_start(rules->inpmap.map[i],
					'T', rules->inpmap.map[i][j]))
				{
					system("open https://www.youtube.com/watch?v=Gszen3QmDM4");
					ft_exit("Non sei degno della nostra ciurma\n");
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (arg_check(ac, av) == 0)
		return (0);
	init_rules(&rules);
	ft_parsing(av[1], &rules);
	// easter_egg(&rules);
	ultimate_check(&rules);
	init_sprite(&rules);
	events(&rules);
	init_xpm_img(&rules, &rules.win_screen, "bonus/textures/winimage.xpm");
	if (fork() == 0)
		system("afplay -v 1.5 mp3/Lilypichu-LavenderTown.mp3");
	else
	{
		mlx_loop_hook(rules.mlx.mlx, loop_events, &rules);
		mlx_loop(rules.mlx.mlx);
	}
}
