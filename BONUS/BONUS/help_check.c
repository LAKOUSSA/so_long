/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:38:30 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:07:37 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_mlx	ft_counint(char *s)
{
	t_mlx	ptr;
	int		i;

	i = 0;
	ptr.size.x = 0;
	ptr.size.y = ft_strlen_new(s);
	while (s[i])
	{
		if (s[i] == '\n')
			ptr.size.x++;
		i++;
	}
	return (ptr);
}

t_mlx	ft_count_collec(t_mlx ptr)
{
	t_loopy	index;

	ptr.col = 0;
	index.i = 0;
	while (index.i < ptr.size.x)
	{
		index.j = 0;
		while (index.j < ptr.size.y)
		{
			if (ptr.area[index.i][index.j] == 'C')
				ptr.col++;
			index.j++;
		}
		index.i++;
	}
	ptr.h = ptr.size.y * 100;
	ptr.w = ptr.size.x * 100;
	return (ptr);
}

t_mlx	rev_search_p(t_mlx ptr)
{
	ptr.p.px = 0;
	while (ptr.p.px < ptr.size.x)
	{
		ptr.p.py = 0;
		while (ptr.p.py < ptr.size.y)
		{
			if (ptr.area[ptr.p.px][ptr.p.py] == 'P')
				return (ptr);
			ptr.p.py++;
		}
		ptr.p.px++;
	}
	return (ptr);
}

t_mlx	rev_search_e(t_mlx ptr)
{
	ptr.e.ex = 0;
	while (ptr.e.ex < ptr.size.x)
	{
		ptr.e.ey = 0;
		while (ptr.e.ey < ptr.size.y)
		{
			if (ptr.area[ptr.e.ex][ptr.e.ey] == 'E')
				return (ptr);
			ptr.e.ey++;
		}
		ptr.e.ex++;
	}
	return (ptr);
}

void	ft_free(char **t, int n)
{
	int	i;

	i = 0;
	if (t[i] == NULL)
	{
		while (i < n)
		{
			free(t[i]);
			i++;
		}
		free(t);
	}
}
