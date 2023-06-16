/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:24:24 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/27 18:28:19 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	r;

	s = 1;
	r = 0;
	i = check(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r * 10 + str[i] - 48 < r && s == -1)
			return (0);
		else if (r * 10 + str[i] - 48 < r && s == 1)
			return (-1);
		r *= 10;
		r += str[i] - 48;
		i++;
	}
	return (r * s);
}
