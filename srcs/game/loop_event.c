/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:01 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/23 14:08:43 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	loop_events(t_rules *rules)
{
	
	//creare condidione che si basa sul numero di frame da vedere
	game(rules);
	
	return (0);
}