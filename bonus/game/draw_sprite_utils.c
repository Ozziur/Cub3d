/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:51:55 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/09 14:54:44 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

int	flag(void)
{
	static int		counter = 0;
	static bool		flag = 0;

	counter++;
	if (counter == 25)
		flag = 1;
	if (counter == 50)
	{
		flag = 0;
		counter = 0;
	}
	return (flag);
}


