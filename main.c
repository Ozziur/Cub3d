/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:11 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 12:26:43 by anovelli         ###   ########.fr       */
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
	t_inputmap *input_map;
	
	if (arg_check(ac, av) == 0)
		return (0);
	printf("culo ok");
	if (!ft_parsing(av[1], input_map))
		return (0);
}