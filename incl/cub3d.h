/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:28 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 15:55:13 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_inputmap
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	char	*f_color;
	char	*c_color;
	char	**map;
}				t_inputmap;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;
}				t_mlx;

typedef struct s_rules
{
	t_mlx	mlx;
}				t_rules;


/*     UTILS      */
//	init.c
void init_mlx(t_mlx *mlx);
void init_rules(t_rules *rules);


#endif