/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:11 by anovelli          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/23 14:29:13 by anovelli         ###   ########.fr       */
=======
/*   Updated: 2023/01/23 14:33:09 by mruizzo          ###   ########.fr       */
>>>>>>> 6aaa3af74e59a1edef155c7909c8e6bf1d1860cf
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

int	arg_check(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "Error: wrong arguments\n", 23);
		return (0);
	}
	else if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		write(1, "Error: invalid file extention\n", 30);
		return (0);
	}
	return (1);
}



int	main(int ac, char **av)
{
	t_rules	rules;

	if (arg_check(ac, av) == 0)
		return (0);
	init_rules(&rules);
	init_mlx(&rules.mlx);
	ft_parsing(av[1], &rules);
<<<<<<< HEAD
					//print_mat(rules.inpmap.map);
	ultimate_check(&rules);
	//signals();
	//free_all();
	//mlx_loop(&rules.mlx.mlx);
=======
	//print_mat(rules.inpmap.map);
	mlx_loop_hook(rules.mlx.mlx, loop_events, &rules);
	print_mat(rules.inpmap.map);
	// mlx_loop(&rules.mlx.mlx);
>>>>>>> 6aaa3af74e59a1edef155c7909c8e6bf1d1860cf
}