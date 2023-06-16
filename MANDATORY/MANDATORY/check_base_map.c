/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_base_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:52:28 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 22:03:30 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_param_and_exist(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid parameter.");
		exit(1);
	}
	ft_check_extension(av[1]);
	fd = open(av[1], O_RDWR);
	if (fd < 0)
	{
		ft_printf("Error\nThe map file not found.");
		exit(1);
	}
	return (fd);
}

void	ft_check_if_rectangular(char *s, t_mlx ptr)
{
	t_reg	reg;

	reg.s = 0;
	reg.k = 0;
	reg.t = malloc(ptr.size.x * sizeof(int));
	while (reg.k < ptr.size.x)
	{
		reg.m = 0;
		reg.n = ft_strlen_new(s + reg.s);
		reg.t[reg.k] = reg.n;
		while (reg.m <= reg.k)
		{
			if (reg.t[reg.m++] != reg.n)
			{
				ft_printf("Error\nThe map must be rectangular.");
				free(reg.t);
				exit(1);
			}
		}
		if (s[reg.n] == '\n')
			reg.n++;
		reg.s += reg.n;
		reg.k++;
	}
	free(reg.t);
}

void	ft_check_characters(t_mlx ptr)
{
	t_loopy	index;

	index.i = 0;
	while (index.i < ptr.size.x)
	{
		index.j = 0;
		while (index.j < ptr.size.y)
		{
			if (ptr.area[index.i][index.j] != '0'
				&& ptr.area[index.i][index.j] != '1'
				&& ptr.area[index.i][index.j] != 'C'
				&& ptr.area[index.i][index.j] != 'E'
				&& ptr.area[index.i][index.j] != 'P')
			{
				ft_printf("Error\nThe map can be composed of only [0,1,C,E,P].");
				exit(1);
			}
			index.j++;
		}
		index.i++;
	}
}

void	ft_check_if_close(t_mlx ptr)
{
	t_loopy	index;

	index.i = 0;
	index.j = 0;
	while (index.j < ptr.size.y)
	{
		if (ptr.area[0][index.j] != '1' || ptr.area[ptr.size.x
			- 1][index.j] != '1')
		{
			ft_printf("Error\nThe map must be closed/surrounded by walls.");
			exit(1);
		}
		index.j++;
	}
	index.j = 0;
	while (index.i < ptr.size.x)
	{
		if (ptr.area[index.i][0] != '1' || ptr.area[index.i][ptr.size.y
			- 1] != '1')
		{
			ft_printf("Error\nThe map must be closed/surrounded by walls.");
			exit(1);
		}
		index.i++;
	}
}

void	ft_check_cep(t_mlx ptr)
{
	t_found	cep;

	cep.i = 0;
	cep.c = 0;
	cep.e = 0;
	cep.p = 0;
	while (cep.i < ptr.size.x)
	{
		cep.j = 0;
		while (cep.j < ptr.size.y)
		{
			if (ptr.area[cep.i][cep.j] == 'E')
				cep.e++;
			if (ptr.area[cep.i][cep.j] == 'C')
				cep.c++;
			if (ptr.area[cep.i][cep.j++] == 'P')
				cep.p++;
		}
		cep.i++;
	}
	if (cep.e != 1 || cep.c < 1 || cep.p != 1)
	{
		ft_printf("Error\nThe map must contain 1E,at least 1C and 1P.");
		exit(1);
	}
}
