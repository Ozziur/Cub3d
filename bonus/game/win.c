/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:10:29 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/07 16:17:22 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

void	ft_win(t_rules *rules)
{

	debug ("ft_win\n");
	rules->win_screen = malloc(sizeof(t_image));
	if (!rules->win_screen)
		ft_exit("Malloc error");
	rules->win_screen->img = mlx_xpm_file_to_image(rules->mlx.mlx, "bonus/textures/exit_win.xpm",
			&rules->mlx.win_width, &rules->mlx.win_height);
	//if (!(*img)->img)
	//init_xpm_img(rules, &rules->win_screen, "bonus/textures/exit_win.xpm");
	debug ("ft_win1\n");
	mlx_put_image_to_window(rules->mlx.mlx, rules->mlx.mlx_win, rules->win_screen->img, rules->mlx.win_width, rules->mlx.win_height);
	
	system("read -n 1 -s -p \"Press any key to continue...\"");
	debug ("ft_win3\n");
	//ft_exit("GGWP\n");
}

int	pick(t_rules *rules, int x, int y)
{
	if (rules->inpmap.map[y][x] == 'H')
		return (1);
	else if (rules->inpmap.map[y][x] == 'T')
		return (2);
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
		rules->flag_hat = 1;
		rules->inpmap.map[y][x] = '0';
	}
	else if (pick(rules, x, y) == 2)
	{
		rules->flag_skull = 1;
		rules->inpmap.map[y][x] = '0';
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
	//ft_exit("u win\n");
}
