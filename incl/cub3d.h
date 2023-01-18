/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:28 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 12:22:54 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

typedef struct	s_inputmap
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	char	**map;

}	t_inputmap;


#endif