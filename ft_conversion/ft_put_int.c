/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:10:05 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/20 18:20:40 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_int_minus(t_args *args, int buf, char *str, int d)
{
	int		res;

	res = 0;
	if (buf < 0 && args->precision >= 0 && d > (int)2147483648)
	{
		res += ft_putchar('-');
	}
	if (args->precision >= 0)
		res += ft_width(args->precision - 1, ft_strlen(str) - 1, 1);
	res += ft_precision(str, ft_strlen(str));
	return (res);
}

int			ft_put_int_helper_1(t_args *args, char *str, int buf, int d)
{
	int		res;

	res = 0;
	if (args->minus == 1)
		res += ft_put_int_minus(args, buf, str, d);
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
		res += ft_put_int_minus(args, buf, str, d);
	return (res);
}

int			ft_put_int_helper_0(t_args *args, int d)
{
	int		res;
	char	*str;
	int		buf;

	res = 0;
	buf = d;
	if (args->precision == 0 && d == 0)
		return ((res += ft_width(args->width, 0, 0)));
	if (d < 0 && (args->precision >= 0 || args->zero == 1))
	{
		if (args->zero == 1 && args->precision < 0 && d > -2147483648)
			res += ft_precision("-", 1);
		d *= -1;
		args->zero = 1;
		args->width--;
	}
	str = ft_itoa(d);
	if (!str)
		return (-1);
	res += ft_put_int_helper_1(args, str, buf, d);
	free(str);
	return (res);
}

int			ft_put_int(t_args *args, va_list ap)
{
	int		res;
	int		d;

	res = 0;
	d = va_arg(ap, int);
	res = ft_put_int_helper_0(args, d);
	return (res);
}
