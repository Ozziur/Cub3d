/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:22:50 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/03 18:47:06 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static void	move_up(t_rules *rules, float rcos, float rsin)
{
	int	res1;
	int	res2;

	res1 = colliding(rules, rcos, 0, 1);
	res2 = colliding(rules, 0, rsin, 1);
	if (!res1)
		rules->player.x += rules->player.d_x * rules->player.speed;
	if (!res2)
		rules->player.y += rules->player.d_y * rules->player.speed;
}

static void	move_down(t_rules *rules, float rcos, float rsin)
{
	int	res1;
	int	res2;

	res1 = colliding(rules, rcos, 0, 0);
	res2 = colliding(rules, 0, rsin, 0);
	if (!res1)
		rules->player.x -= rules->player.d_x * rules->player.speed;
	if (!res2)
		rules->player.y -= rules->player.d_y * rules->player.speed;
}

static void	move_left(t_rules *rules, float rcos, float rsin)
{
	int	res1;
	int	res2;

	res1 = colliding(rules, rsin, 0, 1);
	res2 = colliding(rules, 0, rcos, 0);
	if (!res1)
		rules->player.x += rules->player.d_y * rules->player.speed;
	if (!res2)
		rules->player.y -= rules->player.d_x * rules->player.speed;
}

static void	move_right(t_rules *rules, float rcos, float rsin)
{
	int	res1;
	int	res2;

	res1 = colliding(rules, rsin, 0, 0);
	res2 = colliding(rules, 0, rcos, 1);
	if (!res1)
		rules->player.x -= rules->player.d_y * rules->player.speed;
	if (!res2)
		rules->player.y += rules->player.d_x * rules->player.speed;
}

/*calcolati i valori del coseno e del seno dell'angolo di visuale del 
giocatore moltiplicati per la velocità del giocatore.*/
void	moves(t_rules *rules, char d)
{
	float	rcos;
	float	rsin;

	rcos = rules->player.d_x * rules->player.speed;
	rsin = rules->player.d_y * rules->player.speed;
	if (d == 'w')
		move_up(rules, rcos, rsin);
	else if (d == 'a')
		move_left(rules, rcos, rsin);
	else if (d == 's')
		move_down(rules, rcos, rsin);
	else if (d == 'd')
		move_right(rules, rcos, rsin);
}
