/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:53:47 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:44:02 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_percentage(t_args *args)
{
	int		res;

	args->precision = -1;
	res = 0;
	if (args->minus == 1)
	{
		res += ft_putchar('%');
		res += ft_width(args->width, 1, args->zero);
	}
	else
	{
		res += ft_width(args->width, 1, args->zero);
		res += ft_putchar('%');
	}
	return (res);
}
