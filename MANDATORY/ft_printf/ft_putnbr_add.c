/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:07:48 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/27 18:10:18 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int	ft_putnbr_ha(long n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
	{
		len += ft_putchar(n + 48);
	}
	else if (n >= 10 && n < 16)
	{
		len += ft_putchar(n + 87);
	}
	else
	{
		len += ft_putnbr_ha(n / 16);
		len += ft_putnbr_ha(n % 16);
	}
	return (len);
}

int	ft_putnbr_add(void *n)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putnbr_ha((long)n);
	return (len);
}
