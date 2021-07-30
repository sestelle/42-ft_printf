/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:50:50 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 13:19:44 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion(va_list ap, t_args *args)
{
	int		res;

	res = 0;
	if (args->type == 'd' || args->type == 'i')
		res += ft_put_int(args, ap);
	else if (args->type == 'c')
		res += ft_put_char(args, ap);
	else if (args->type == 's')
		res += ft_put_str(args, ap);
	else if (args->type == 'p')
		res += ft_put_pointer(args, ap);
	else if (args->type == 'x' || args->type == 'X')
		res += ft_put_x(args, ap);
	else if (args->type == 'u')
		res += ft_put_uint(args, ap);
	else if (args->type == '%')
		res += ft_put_percentage(args);
	return (res);
}
