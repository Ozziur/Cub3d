/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:32:08 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/08 15:05:10 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	ft_win(t_rules *rules)
{
	//init_xpm_img(rules, &rules->win_screen, "textures/mruizzo_Pirate_and_Mage_Spending_Time_Together_in_the_Tower_In__191e48ae-1889-4d5a-9136-8cbb1ef0a863.xpm");
 	mlx_put_image_to_window(rules->mlx.mlx, rules->mlx.mlx_win, rules->win_screen->img, 0, 0);
	rules->won = 1;
}

int	pick(t_rules *rules, int x, int y)
{
	if (rules->inpmap.map[y][x] == 'H')
		return (2);
	else if (rules->inpmap.map[y][x] == 'T')
		return (1);
	return (0);
}

void	collect(t_rules *rules)
{
	int	x;
	int	y;

	x = (int)(rules->player.x / rules->inpmap.block_width);
	y = (int)(rules->player.y / rules->inpmap.block_width);
	if (pick(rules, x, y) == 1)
	{
		rules->flag_skull = 1;
		rules->inpmap.map[y][x] = '0';
		free(rules->animations[0]);
		free(rules->animations[1]);
		rules->animations[0] = NULL;
		rules->animations[1] = NULL;
	}
	else if (pick(rules, x, y) == 2)
	{
		rules->flag_hat = 1;
		rules->inpmap.map[y][x] = '0';
		free(rules->animations[2]);
		free(rules->animations[3]);
		rules->animations[2] = NULL;
		rules->animations[3] = NULL;
	}
}

static int	is_open(t_rules *rules, int x, int y)
{
	if (rules->inpmap.map[y][x] == '*' && rules->flag_hat && rules->flag_skull)
		return (1);
	return (0);
}

void	ft_openexit(t_rules *rules)
{
	int	x;
	int	y;

	x = (int)(rules->player.x / rules->inpmap.block_width);
	y = (int)(rules->player.y / rules->inpmap.block_width);
	if (rules->player.dir < M_PI / 4 || rules->player.dir > 2 * M_PI - M_PI / 4)
		x++;
	if (rules->player.dir > M_PI + M_PI / 4
		&& rules->player.dir < 2 * M_PI - M_PI / 4)
		y++;
	if (rules->player.dir > M_PI / 4 && rules->player.dir < M_PI - M_PI / 4)
		y--;
	if (rules->player.dir > M_PI - M_PI / 4
		&& rules->player.dir < M_PI + M_PI / 4)
		x--;
	if (is_open(rules, x, y))
		rules->win_flag = 1;
}
