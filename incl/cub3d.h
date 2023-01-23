/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:28 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/23 14:35:10 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp; //mlx_get_data_addr
	int		line_length; //mlx_get_data_addr
	int		endian; //mlx_get_data_addr
	int		width;
	int		height;
}				t_image;

typedef struct	s_inputmap
{
	t_image			*north_wall;
	t_image			*south_wall;
	t_image			*east_wall;
	t_image			*west_wall;
	unsigned char	f_color[3];
	bool			floor;
	unsigned char	c_color[3];
	bool			ceiling;	
	char			**map;
	int				map_height_len[2];
	int				line_offset;
	
	float			block_width; //parametro float per rayc
	float			mini_block_width; //parametro float per rayc della minimappa
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
	t_inputmap	inpmap;
}				t_rules;


/*     UTILS      */
//	init.c
void	init_mlx(t_mlx *mlx);
void	init_rules(t_rules *rules);
void	init_img(t_rules *rules, t_image *img, int w, int h);
/*		PARSING    */
//	parse_map.c
void	ft_parsing(char *input, t_rules *rules);
//	get_rules.c
void	save_rule(char *buf, t_rules *rules);

/*     GAME      */
// loop_event.c
int	loop_events(t_rules *rules);
// game
void	game(t_rules *rules);

//debug
void	debug(char *s);
void	ft_exit(char *str);
void	print_mat(char **mat);
void	printrules(t_rules *rules);
//	check.c
void	ultimate_check(t_rules *rules);



#endif