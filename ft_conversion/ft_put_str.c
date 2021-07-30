/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:22:31 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/21 18:37:28 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		ft_put_str_helper(t_args *args, char *str)
{
	int		res;

	res = 0;
	if (args->minus == 1)
	{
		res += ft_putstr(str);
		res += ft_width(args->width, ft_strlen(str), args->zero);
	}
	else
	{
		res += ft_width(args->width, ft_strlen(str), args->zero);
		res += ft_putstr(str);
	}
	return (res);
}

int		ft_put_str(t_args *args, va_list ap)
{
	int		res;
	char	*str;
	char	*str_cpy;

	res = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str_cpy = ft_strdup("(null)");
		if (!str_cpy)
			return (-1);
	}
	else
		str_cpy = ft_strdup(str);
	if (!str_cpy)
		return (-1);
	str = str_cpy;
	if (args->precision > -1)
		*(str + args->precision) = '\0';
	args->precision = ft_strlen(str);
	res += ft_put_str_helper(args, str);
	free(str_cpy);
	return (res);
}
