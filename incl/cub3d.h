/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:28 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 18:36:07 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	// int		bpp; da capire
	// int		line_length; da capire
	// int		endian; da capire
	int		width;
	int		height;
}				t_image;

typedef struct	s_inputmap
{
	t_image	*north_path;
	t_image	*south_path;
	t_image	*east_path;
	t_image	*west_path;
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
	t_inputmap	*inpmap;
}				t_rules;


/*     UTILS      */
//	init.c
void init_mlx(t_mlx *mlx);
void init_rules(t_rules *rules);
/*		PARSING    */
//	parse_map.c
void ft_parsing(char *input, t_rules *rules);


#endif