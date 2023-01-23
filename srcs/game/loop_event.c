/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:01 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/23 17:33:12 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	loop_events(t_rules *rules)
{
	//creare condidione che si basa sul numero di frame da vedere
	printf( "FCOLOOORRR -> %d  %d %d \n" , rules->inpmap.f_color[0],rules->inpmap.f_color[1],rules->inpmap.f_color[2]);
	game(rules);
	return (0);
}