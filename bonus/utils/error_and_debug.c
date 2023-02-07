/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:19 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/07 14:12:20 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	printrules(t_rules *rules)
{
	printf("%p %p %p %p %d %d\n", rules->inpmap.north_wall,
		rules->inpmap.south_wall,
		rules->inpmap.east_wall, rules->inpmap.west_wall,
		rules->inpmap.floor, rules->inpmap.ceiling);
}

void	debug(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	print_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		printf("%d -> %s\n", i, mat[i]);
		i++;
	}
}

void	ft_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	print_moves(t_rules *rules, int key)
{
	printf(YELLOW "[DEBUG] -----------------------------------\n"
		RESET "posx: %lf\nposy: %lf\nkeycode: %d\n",
		rules->player.x, rules->player.y, key);
}
