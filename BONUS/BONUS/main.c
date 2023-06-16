/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:36:26 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:07:37 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int ac, char *av[])
{
	t_mlx	ptr;

	ptr = ft_read_check(ac, av);
	ptr.mlx = mlx_init();
	ptr.timer = 0;
	ptr.index_e = 0;
	ptr.index_c = 0;
	ptr.win = mlx_new_window(ptr.mlx, ptr.size.y * 100, ptr.size.x * 100,
			"so_long");
	ptr = display_all(&ptr);
	mlx_hook(ptr.win, 2, 0, my_key_funct, &ptr);
	mlx_loop_hook(ptr.mlx, animated, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
