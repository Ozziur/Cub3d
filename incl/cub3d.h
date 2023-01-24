/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:28 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/24 15:59:49 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define _USE_MATH_DEFINES

# define ANGLE_UNIT 0.00174 //capire
# define SPEED 3 //capire

typedef struct s_ray
{
	double		angle;
	float		x;
	float		y;
	float		xyoff[2];
}				t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	double	d_x;
	double	d_y;
	double	dir;
	float	speed;
}				t_player;

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

typedef struct s_bres_data
{
	float			xy[2];
	float			xy2[2];
	unsigned int	color;
	int				x;
	double			ray_angle;
}				t_bres_data;

typedef struct s_inputmap
{
	t_image			*north_wall;
	t_image			*south_wall;
	t_image			*east_wall;
	t_image			*west_wall;
	unsigned char	f_color[3];
	unsigned char	c_color[3];
	bool			floor;
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

typedef struct s_bres_info
{
	int				swap;
	double			ab[2];
	double			d;
	int				sq[2];
	int				axy[2];
	unsigned int	color;
}				t_bres_info;

typedef struct s_draw_info
{
	t_bres_data	d;
	t_image		*view;
	t_image		*tex;
	double		l_h;
	double		off;
}				t_draw_info;

typedef struct s_rules
{
	t_mlx		mlx;
	t_inputmap	inpmap;
	t_player	player;
}				t_rules;

/*     UTILS      */
//	init.c
void			init_mlx(t_mlx *mlx);
void			init_rules(t_rules *rules);
void			init_img(t_rules *rules, t_image *img, int w, int h);
//img utils
void			easy_pxl(t_image *image, int x, int y, int color);
unsigned int	get_color_arr(unsigned char arr[3]);
unsigned int	color_pxl(t_image *tex, int x, int y, t_rules *rules);
//math_stuf.c
double			decrement_angle(double angle, int t);
double			increment_angle(double angle, int t);
double			final_length(float start_x, float start_y, float rxy[2]);
double			final_length_double(double start_x,
					double start_y, double rxy[2]);
//easy_math.c
int				get_abs(int n);
double			get_abs_double(double n);
double			our_modulo(double x, double y);
double			get_dist(t_rules *rules, t_bres_data *d);
double			get_fix(double angle);
//choose
t_image			*choose_texture(t_rules *rules, t_bres_data *d);
int				choose_x(t_draw_info *info, float ref, t_rules *rules);
int				choose_y(int var, t_draw_info *info);

/*		PARSING    */
//	parse_map.c
void			ft_parsing(char *input, t_rules *rules);
//	get_rules.c
void			save_rule(char *buf, t_rules *rules);

/*     GAME      */
// 			loop_event.c
int				loop_events(t_rules *rules);
// 			game.c
void			game(t_rules *rules);
//			raycast.c
void			raycast(t_rules *rules, t_image *view, t_image *minimap);
int				virtual_vertical_colliding(int ray_x, int ray_y, t_rules *rules, int dir);
int				virtual_horizontal_colliding(int ray_x, int ray_y, t_rules *rules, int dir);
//			raycastcalc
void			raycast_calc(t_bres_data *data, t_rules *rules,
			t_image *view, t_image *minimap);
//bres_algo.c
void			bresenham(t_bres_data *d, t_image *min, t_image *view,
					t_rules *rules);
// render.c
void			draw_view(t_bres_data *d, t_image *view,
					t_rules *rules, t_image *tex);
			
//			debug
void			debug(char *s);
void			ft_exit(char *str);
void			print_mat(char **mat);
void			printrules(t_rules *rules);
//			check.c
void			ultimate_check(t_rules *rules);

#endif