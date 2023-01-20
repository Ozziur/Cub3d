/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:19 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/20 23:14:22 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void printrules(t_rules *rules)
{
	printf("%p %p %p %p %d %d\n", rules->inpmap.north_wall , rules->inpmap.south_wall
		, rules->inpmap.east_wall , rules->inpmap.west_wall
		, rules->inpmap.floor , rules->inpmap.ceiling);
}