/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:50:40 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:07:37 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	end_move(t_mlx *ptr, int *move)
{
	char	*s;

	ft_printf("LAST MOVE ==>  %d\n", ++(*move));
	s = ft_itoa(*move);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_0, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->moves, 2, 1);
	mlx_string_put(ptr->mlx, ptr->win, 40, 5, 5, s);
	ft_printf("GAME OVER\n");
	free(s);
	exit(1);
}

void	curr_move(t_mlx *ptr, int *move)
{
	char	*s;

	ft_printf("MOVE ==>  %d\n", ++(*move));
	s = ft_itoa(*move);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_0, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->moves, 2, 1);
	mlx_string_put(ptr->mlx, ptr->win, 40, 5, 5, s);
	free(s);
}
