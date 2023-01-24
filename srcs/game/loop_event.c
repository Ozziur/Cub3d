/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:01 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/24 14:22:33 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"


void	let_keys_work(t_rules *rules)
{

}

int	loop_events(t_rules *rules)
{
	let_keys_work(rules);
	//creare condidione che si basa sul numero di frame da vedere
	game(rules);
	return (0);
}
