/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:06:17 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:44:02 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_char(t_args *args, va_list ap)
{
	int		res;
	char	c;

	res = 0;
	c = va_arg(ap, int);
	if (args->minus == 1)
	{
		res += ft_putchar(c);
		res += ft_width(args->width, 1, args->zero);
	}
	else
	{
		res += ft_width(args->width, 1, args->zero);
		res += ft_putchar(c);
	}
	return (res);
}
