/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:01 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/23 17:48:04 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	loop_events(t_rules *rules)
{
	//creare condidione che si basa sul numero di frame da vedere
	printf("cielo-> %d   %d  %d  \n", rules->inpmap.c_color[0], rules->inpmap.c_color[1], rules->inpmap.c_color[2]);
	game(rules);
	return (0);
}