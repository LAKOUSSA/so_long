/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:18:15 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 22:40:32 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_extension(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] != 'r' || s[i - 1] != 'e' || s[i - 2] != 'b' || s[i - 3] != '.')
	{
		ft_printf("Error\nThe map file must end with the <.ber> extension.");
		exit(1);
	}
}

t_mlx	make_area(char *zone, t_mlx ptr)
{
	t_loopy	index;
	int		c;

	index.i = 0;
	c = 0;
	ptr.area = malloc(sizeof(char *) * ptr.size.x);
	while (ptr.area && zone[c] && index.i < ptr.size.x)
	{
		index.j = 0;
		ptr.area[index.i] = malloc(ptr.size.y + 1);
		while (ptr.area[index.i] && zone[c] && index.j < ptr.size.y)
		{
			if (zone[c] == '\n')
				c++;
			ptr.area[index.i][index.j] = zone[c];
			index.j++;
			c++;
		}
		ft_free(ptr.area, index.i);
		ptr.area[index.i][ptr.size.y] = '\0';
		index.i++;
	}
	return (ptr);
}

t_mlx	ft_check_all(t_mlx ptr, char *zone)
{
	ft_check_if_rectangular(zone, ptr);
	ptr = make_area(zone, ptr);
	free(zone);
	ft_check_path(ptr);
	ft_check_characters(ptr);
	ft_check_if_close(ptr);
	ft_check_cep(ptr);
	ptr = ft_count_collec(ptr);
	return (ptr);
}

t_mlx	ft_read_check(int ac, char *av[])
{
	int		fd;
	char	*s;
	char	*zone;
	t_mlx	ptr;

	zone = NULL;
	fd = ft_check_param_and_exist(ac, av);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL || s[0] == '\n' || ft_strlen(s) == 1)
			break ;
		zone = ft_strjoin(zone, s);
		free(s);
	}
	if (!zone)
	{
		ft_printf("Error\nEMPTY LINE");
		exit(1);
	}
	ptr = ft_counint(zone);
	ptr = ft_check_all(ptr, zone);
	return (ptr);
}
