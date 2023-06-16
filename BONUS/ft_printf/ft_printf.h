/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:28:35 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:52:46 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_flags
{
	char	space;
	char	hash;
	char	plus;
}			t_flags;

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr_add(void *n);
int			ft_putnbr(int n);
int			ft_putnbr_(int n);
int			ft_putnbr_hupp(int n);
int			ft_putnbr_hlow(int n);
int			ft_printf(const char *s, ...);

#endif
