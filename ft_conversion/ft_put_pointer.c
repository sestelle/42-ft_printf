/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:57:05 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/20 18:25:17 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

static int	ft_put_p_helper_2(t_args *args, char *str)
{
	int		res;

	res = 0;
	res += ft_precision("0x", 2);
	if (args->precision >= 0)
	{
		res += ft_width(args->precision - 1, ft_strlen(str), args->zero);
		res += ft_precision(str, args->precision);
	}
	else
		res += ft_precision(str, ft_strlen(str));
	return (res);
}

static int	ft_put_p_helper_1(t_args *args, char *str)
{
	int		res;

	res = 0;
	if (args->minus == 0)
	{
		res += ft_width(args->width, ft_strlen(str) + 2, args->zero);
		res += ft_put_p_helper_2(args, str);
	}
	else
	{
		res += ft_put_p_helper_2(args, str);
		res += ft_width(args->width, ft_strlen(str) + 2, args->zero);
	}
	return (res);
}

static char	*ft_prepare_str(unsigned long p, char *str)
{
	unsigned long	buf;
	int				counter;

	counter = 0;
	buf = p;
	if (p == 0)
		str = ft_strdup("0");
	else
	{
		while (buf != 0)
		{
			buf /= 16;
			counter++;
		}
		if ((str = (char *)malloc(sizeof(char) * (counter + 1))) == NULL)
			return (NULL);
		str[counter] = '\0';
		while (p != 0)
		{
			str[--counter] = (p % 16 < 10) ? (p % 16) + 48 : (p % 16) + 87;
			p /= 16;
		}
	}
	return (str);
}

int			ft_put_p_helper_0(t_args *args, unsigned long p)
{
	int				res;
	char			*str;
	unsigned long	buf;

	res = 0;
	buf = p;
	str = NULL;
	if (p == 0 && args->precision == 0)
	{
		str = ft_strdup("0x");
		res += ft_precision(str, ft_strlen(str));
		free(str);
		res += ft_width(args->width, 0, 1);
		return (res);
	}
	else
	{
		str = ft_prepare_str(buf, str);
		if (!str)
			return (-1);
		res += ft_put_p_helper_1(args, str);
		free(str);
	}
	return (res);
}

int			ft_put_pointer(t_args *args, va_list ap)
{
	int				res;
	unsigned long	p;

	res = 0;
	p = va_arg(ap, unsigned long);
	res = ft_put_p_helper_0(args, p);
	return (res);
}
