/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:34:01 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:07:37 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
		exit(0);
	}
	*ptr = ft_loop(keycode, *ptr);
	return (0);
}

void	move_w(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'S')
	{
		ft_printf("YOU LOSE\n");
		exit(1);
	}
	else if (ptr->area[ptr->p.px - 1][ptr->p.py] == '0' || ptr->area[ptr->p.px
			- 1][ptr->p.py] == 'C')
	{
		if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px - 1][ptr->p.py] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		curr_move(ptr, move);
	}
	else if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'E' && !ptr->col)
		end_move(ptr, move);
}

void	move_a(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'S')
	{
		ft_printf("YOU LOSE\n");
		exit(1);
	}
	else if (ptr->area[ptr->p.px][ptr->p.py - 1] == '0'
			|| ptr->area[ptr->p.px][ptr->p.py - 1] == 'C')
	{
		if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px][ptr->p.py - 1] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		curr_move(ptr, move);
	}
	else if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'E' && !ptr->col)
		end_move(ptr, move);
}

void	move_s(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'S')
	{
		ft_printf("YOU LOSE\n");
		exit(1);
	}
	else if (ptr->area[ptr->p.px + 1][ptr->p.py] == '0' || ptr->area[ptr->p.px
			+ 1][ptr->p.py] == 'C')
	{
		if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px + 1][ptr->p.py] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		curr_move(ptr, move);
	}
	else if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'E' && !ptr->col)
		end_move(ptr, move);
}

void	move_d(t_mlx *ptr, int *move)
{
	if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'S')
	{
		ft_printf("YOU LOSE\n");
		exit(1);
	}
	else if (ptr->area[ptr->p.px][ptr->p.py + 1] == '0'
			|| ptr->area[ptr->p.px][ptr->p.py + 1] == 'C')
	{
		if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px][ptr->p.py + 1] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
		curr_move(ptr, move);
	}
	else if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'E' && !ptr->col)
		end_move(ptr, move);
}
