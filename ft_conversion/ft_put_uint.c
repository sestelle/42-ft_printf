/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:34:14 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/20 18:34:51 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_uint_minus(t_args *args, unsigned int buf, char *str)
{
	int		res;

	res = 0;
	if (buf < 0 && args->precision >= 0)
		res += ft_putchar('-');
	if (args->precision >= 0)
		res += ft_width(args->precision - 1, ft_strlen(str) - 1, 1);
	res += ft_precision(str, ft_strlen(str));
	return (res);
}

int			ft_put_uint_helper_1(t_args *args, char *str, unsigned int buf)
{
	int		res;

	res = 0;
	if (args->minus == 1)
		res += ft_put_uint_minus(args, buf, str);
	if (args->precision >= 0 && (size_t)args->precision < ft_strlen(str))
		args->precision = ft_strlen(str);
	if (args->precision >= 0)
	{
		args->width -= args->precision;
		res += ft_width(args->width, 0, 0);
	}
	else
		res += ft_width(args->width, ft_strlen(str), args->zero);
	if (args->minus == 0)
		res += ft_put_uint_minus(args, buf, str);
	return (res);
}

int			ft_put_uint_helper_0(t_args *args, unsigned int d)
{
	int				res;
	char			*str;
	unsigned int	buf;

	res = 0;
	buf = d;
	if (args->precision == 0 && d == 0)
		return ((res += ft_width(args->width, 0, 0)));
	if (d < 0 && (args->precision >= 0 || args->zero == 1))
	{
		if (args->zero == 1 && args->precision < 0)
			res += ft_precision("-", 1);
		d *= -1;
		args->width--;
	}
	str = ft_uitoa(d);
	if (!str)
		return (-1);
	res += ft_put_uint_helper_1(args, str, buf);
	free(str);
	return (res);
}

int			ft_put_uint(t_args *args, va_list ap)
{
	int				res;
	unsigned int	d;

	res = 0;
	d = va_arg(ap, unsigned int);
	res = ft_put_uint_helper_0(args, d);
	return (res);
}
