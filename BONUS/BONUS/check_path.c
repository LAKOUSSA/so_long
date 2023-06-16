/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:19 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:07:37 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**ft_copy_area(t_mlx ptr)
{
	char	**areacopy;
	t_loopy	index;

	index.i = 0;
	areacopy = malloc(sizeof(char *) * ptr.size.x);
	if (!areacopy)
		return (NULL);
	while (index.i < ptr.size.x)
	{
		areacopy[index.i] = ft_strdup(ptr.area[index.i]);
		ft_free(areacopy, index.i);
		index.i++;
	}
	return (areacopy);
}

void	rev_path_c(char **s, int x, int y, t_mlx ptr)
{
	if (x < 0 || y < 0 || x >= ptr.size.x || y >= ptr.size.y || s[x][y] == 'F'
		|| (s[x][y] != 'C' && s[x][y] != '0' && s[x][y] != 'P'))
		return ;
	s[x][y] = 'F';
	rev_path_c(s, x, y + 1, ptr);
	rev_path_c(s, x, y - 1, ptr);
	rev_path_c(s, x + 1, y, ptr);
	rev_path_c(s, x - 1, y, ptr);
}

void	rev_path_e(char **s, int x, int y, t_mlx ptr)
{
	if (x < 0 || y < 0 || x >= ptr.size.x || y >= ptr.size.y || s[x][y] == 'X'
		|| (s[x][y] != 'E' && s[x][y] != 'F'))
		return ;
	s[x][y] = 'X';
	rev_path_e(s, x, y + 1, ptr);
	rev_path_e(s, x, y - 1, ptr);
	rev_path_e(s, x + 1, y, ptr);
	rev_path_e(s, x - 1, y, ptr);
}

void	rev_path_collec(char **s, t_mlx ptr)
{
	t_loopy	index;

	index.i = 0;
	index.j = 0;
	while (index.i < ptr.size.x)
	{
		index.j = 0;
		while (index.j < ptr.size.y)
		{
			if (s[index.i][index.j] == 'C')
			{
				ft_printf("Error\nThere’s an invalid path to COLLEC");
				exit(0);
			}
			index.j++;
		}
		index.i++;
	}
}

void	ft_check_path(t_mlx ptr)
{
	ptr.areacopy = ft_copy_area(ptr);
	ptr = rev_search_p(ptr);
	rev_path_c(ptr.areacopy, ptr.p.px, ptr.p.py, ptr);
	rev_path_collec(ptr.areacopy, ptr);
	rev_path_e(ptr.areacopy, ptr.p.px, ptr.p.py, ptr);
	ptr.p.px = 0;
	ptr.p.py = 0;
	while (ptr.p.px < ptr.size.x)
	{
		ptr.p.py = 0;
		while (ptr.p.py < ptr.size.y)
		{
			if (ptr.areacopy[ptr.p.px][ptr.p.py] == 'E')
			{
				ft_printf("Error\nThere’s an invalid path to EXIT.");
				exit(0);
			}
			ptr.p.py++;
		}
		ptr.p.px++;
	}
	ptr.p.px = 0;
	while (ptr.p.px < ptr.size.x)
		free(ptr.areacopy[ptr.p.px++]);
	free(ptr.areacopy);
}
