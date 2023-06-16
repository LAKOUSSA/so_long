/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:36:26 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 22:41:32 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destrooy(t_mlx *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	ft_printf("BYE\n");
	exit (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_mlx	ptr;

	ptr = ft_read_check(ac, av);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.size.y * 100, ptr.size.x * 100,
			"so_long");
	ptr = display_all(&ptr);
	mlx_hook(ptr.win, 2, 0, my_key_funct, &ptr);
	mlx_hook(ptr.win, 17, 0, destrooy, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
