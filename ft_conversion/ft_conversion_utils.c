/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:04:04 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:44:02 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(int width, int min, int is_zero)
{
	int		res;

	res = 0;
	while (width - min > 0)
	{
		if (is_zero)
			res += ft_putchar('0');
		else
			res += ft_putchar(' ');
		width--;
	}
	return (res);
}

int		ft_precision(char *str, int precision)
{
	int		res;

	res = 0;
	while (str[res] && res < precision)
		res += ft_putchar(str[res]);
	return (res);
}
