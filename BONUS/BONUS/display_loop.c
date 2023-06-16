/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:56:41 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:45:00 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_mlx	display_all(t_mlx *ptr)
{
	t_loopy	index;

	ptr = creation_textures(ptr);
	index.i = -1;
	while (++index.i < ptr->size.x)
	{
		index.j = -1;
		while (++index.j < ptr->size.y)
		{
			if (ptr->area[index.i][index.j] == 'P')
				ft_put_image(*ptr, ptr->player, index);
			else if (ptr->area[index.i][index.j] == 'C')
				ft_put_image(*ptr, ptr->collect, index);
			else if (ptr->area[index.i][index.j] == '0')
				ft_put_image(*ptr, ptr->space, index);
			else if (ptr->area[index.i][index.j] == 'E')
				ft_put_image(*ptr, ptr->exit_0, index);
			else if (ptr->area[index.i][index.j] == '1')
				full_wall(ptr, index);
		}
	}
	*ptr = rev_search_p(*ptr);
	return (*ptr);
}

int	right_moves(t_mlx ptr, int d, t_loopy index)
{
	{
		if (!d)
		{
			ft_put_image(ptr, ptr.right1, index);
			d = 1;
		}
		else if (d)
		{
			ft_put_image(ptr, ptr.right2, index);
			d = 0;
		}
	}
	return (d);
}

int	left_moves(t_mlx ptr, int a, t_loopy index)
{
	if (!a)
	{
		ft_put_image(ptr, ptr.left1, index);
		a = 1;
	}
	else if (a)
	{
		ft_put_image(ptr, ptr.left2, index);
		a = 0;
	}
	return (a);
}

void	mini_loop(t_mlx ptr, t_loopy index, int a, int d)
{
	if (ptr.key == 13 || ptr.key == 1)
		ft_put_image(ptr, ptr.player, index);
	if (ptr.key == 0 && ptr.area[ptr.p.px][ptr.p.py - 1] != '1')
		a = left_moves(ptr, a, index);
	if (ptr.key == 2 && ptr.area[ptr.p.px][ptr.p.py + 1] != '1')
		d = right_moves(ptr, d, index);
}

t_mlx	ft_loop(int keycode, t_mlx ptr)
{
	t_loopy		index;
	static int	a;
	static int	d;

	ptr.key = keycode;
	index.i = -1;
	while (++index.i < ptr.size.x)
	{
		index.j = -1;
		while (++index.j < ptr.size.y)
		{
			if (ptr.area[index.i][index.j] == 'P')
				mini_loop(ptr, index, a, d);
			else if (ptr.area[index.i][index.j] == 'E')
				ft_put_image(ptr, ptr.exit_0, index);
			else if (ptr.area[index.i][index.j] == '0')
				ft_put_image(ptr, ptr.space, index);
		}
	}
	ptr = rev_search_e(ptr);
	if (!ptr.col)
		mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.exit_1, ptr.e.ey * 100,
			ptr.e.ex * 100);
	ptr = rev_search_p(ptr);
	return (ptr);
}
