/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:39:49 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/20 18:22:25 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_prepare_lower_upper_str(char *str, int counter,
				unsigned int buf, int capitals)
{
	if (capitals == 1)
	{
		while (buf != 0)
		{
			if ((buf % 16) < 10)
				str[counter] = (buf % 16) + 48;
			else
				str[counter] = (buf % 16) + 55;
			buf /= 16;
			counter--;
		}
	}
	else
	{
		while (buf != 0)
		{
			if ((buf % 16) < 10)
				str[counter] = (buf % 16) + 48;
			else
				str[counter] = (buf % 16) + 87;
			buf /= 16;
			counter--;
		}
	}
	return (str);
}

static char		*ft_prepare_str(unsigned int d, int capitals, char *str)
{
	unsigned long	i;
	int				counter;

	i = d;
	counter = 0;
	if (i == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else
	{
		while (i != 0)
		{
			i /= 16;
			counter++;
		}
		i = d;
		str = malloc(sizeof(char) * (counter + 1));
		if (!str)
			return (NULL);
		str[counter] = '\0';
		str = ft_prepare_lower_upper_str(str, --counter, i, capitals);
	}
	return (str);
}

static int		ft_put_x_helper_1(t_args *args, char *str)
{
	int		res;

	res = 0;
	if (args->minus == 1)
	{
		if (args->precision >= 0)
			res += ft_width(args->precision, ft_strlen(str), 1);
		res += ft_precision(str, ft_strlen(str));
	}
	if (args->precision >= 0 && args->precision < (int)ft_strlen(str))
		args->precision = ft_strlen(str);
	if (args->precision >= 0)
	{
		args->width -= args->precision;
		res += ft_width(args->width, 0, 0);
	}
	else
		res += ft_width(args->width, ft_strlen(str), args->zero);
	if (args->minus == 0)
	{
		if (args->precision >= 0)
			res += ft_width(args->precision, ft_strlen(str), 1);
		res += ft_precision(str, ft_strlen(str));
	}
	return (res);
}

static int		ft_put_x_helper_0(t_args *args, unsigned int d, int capitals)
{
	int				res;
	unsigned long	i;
	char			*str;
	int				counter;

	res = 0;
	counter = 0;
	str = NULL;
	i = d;
	if (args->precision == 0 && d == 0)
	{
		res += ft_width(args->width, 0, 0);
		return (res);
	}
	else
	{
		str = ft_prepare_str(i, capitals, str);
		if (!str)
			return (-1);
	}
	counter = 0;
	res += ft_put_x_helper_1(args, str);
	free(str);
	return (res);
}

int				ft_put_x(t_args *args, va_list ap)
{
	int		res;
	int		d;
	int		capitals;

	res = 0;
	if (args->type == 'x')
		capitals = 0;
	else
		capitals = 1;
	d = va_arg(ap, unsigned int);
	res += ft_put_x_helper_0(args, d, capitals);
	return (res);
}
