/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:34:01 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 22:03:58 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	my_key_funct(int keycode, t_mlx *ptr)
{
	static int	i;

	if (keycode == 13)
		move_w(ptr, &i);
	else if (keycode == 0)
		move_a(ptr, &i);
	else if (keycode == 1)
		move_s(ptr, &i);
	else if (keycode == 2)
		move_d(ptr, &i);
	else if (keycode == 53)
	{
		ft_printf("EXIT\n");
		exit(1);
	}
	*ptr = ft_loop(keycode, *ptr);
	return (0);
}

void	move_w(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px - 1][ptr->p.py] == '0' || ptr->area[ptr->p.px
		- 1][ptr->p.py] == 'C')
	{
		if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px - 1][ptr->p.py] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		ft_printf("MOVE ==>  %d\n", ++(*move));
	}
	else if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'E' && !ptr->col)
	{
		ft_printf("LAST MOVE ==>  %d\n", ++(*move));
		ft_printf("GAME OVER\n");
		exit(0);
	}
}

void	move_a(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px][ptr->p.py - 1] == '0'
		|| ptr->area[ptr->p.px][ptr->p.py - 1] == 'C')
	{
		if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px][ptr->p.py - 1] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		ft_printf("MOVE ==>  %d\n", ++(*move));
	}
	else if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'E' && !ptr->col)
	{
		ft_printf("LAST MOVE ==>  %d\n", ++(*move));
		ft_printf("GAME OVER\n");
		exit(0);
	}
}

void	move_s(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px + 1][ptr->p.py] == '0' || ptr->area[ptr->p.px
		+ 1][ptr->p.py] == 'C')
	{
		if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px + 1][ptr->p.py] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		ft_printf("MOVE ==>  %d\n", ++(*move));
	}
	else if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'E' && !ptr->col)
	{
		ft_printf("LAST MOVE ==>  %d\n", ++(*move));
		ft_printf("GAME OVER\n");
		exit(0);
	}
}

void	move_d(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px][ptr->p.py + 1] == '0'
		|| ptr->area[ptr->p.px][ptr->p.py + 1] == 'C')
	{
		if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px][ptr->p.py + 1] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		ft_printf("MOVE ==>  %d\n", ++(*move));
	}
	else if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'E' && !ptr->col)
	{
		ft_printf("LAST MOVE ==>  %d\n", ++(*move));
		ft_printf("GAME OVER\n");
		exit(0);
	}
}
