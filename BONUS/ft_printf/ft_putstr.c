/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:29:51 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/27 18:27:57 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	if (!s)
		return (len);
	i = 0;
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}
