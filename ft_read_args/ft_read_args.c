/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:36:45 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:44:02 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_read_minus(char *itr, t_args *args)
{
	while (*itr == '-' || *itr == '0')
	{
		if (*itr == '-')
			args->minus = 1;
		if (*itr == '0')
			args->zero = 1;
		itr++;
	}
	return (itr);
}

static char	*ft_read_width(char *itr, t_args *args, va_list ap)
{
	if (*itr == '0')
	{
		args->zero = 1;
		itr++;
	}
	if (*itr == '*')
	{
		args->width = va_arg(ap, int);
		if (args->width < 0)
		{
			args->minus = 1;
			args->zero = 0;
			args->width *= -1;
		}
		itr++;
	}
	else
	{
		args->width = ft_atoi(itr);
		while (ft_isdigit(*itr))
			itr++;
	}
	return (itr);
}

static char	*ft_read_precision(char *itr, t_args *args, va_list ap)
{
	if (*itr == '.')
	{
		itr++;
		if (*itr == '*')
		{
			args->precision = va_arg(ap, int);
			if (args->precision < 0)
				args->precision = -1;
			itr++;
		}
		else
		{
			if (ft_isdigit(*itr))
			{
				args->precision = ft_atoi(itr);
				if (args->precision < 0)
					args->precision = -1;
				while (ft_isdigit(*itr))
					itr++;
			}
			else
				args->precision = 0;
		}
	}
	return (itr);
}

static char	*ft_read_conversion(char *itr, t_args *args)
{
	if (ft_strchr("cspdiuxX%", *itr))
	{
		args->type = *itr;
		itr++;
	}
	return (itr);
}

char		*ft_read_args(char *itr, t_args *args, va_list ap)
{
	itr++;
	args = ft_init_args(args);
	if (*itr == ' ')
		itr++;
	itr = ft_read_minus(itr, args);
	if (args->minus == 1)
		args->zero = 0;
	itr = ft_read_width(itr, args, ap);
	itr = ft_read_precision(itr, args, ap);
	itr = ft_read_conversion(itr, args);
	return (itr);
}
