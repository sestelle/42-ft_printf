/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:28:03 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 13:22:29 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;
	t_args	args;
	char	*itr;
	int		i;

	res = 0;
	va_start(ap, format);
	itr = (char *)format;
	while (*itr)
	{
		if (*itr == '%')
		{
			itr = ft_read_args(itr, &args, ap);
			i = ft_conversion(ap, &args);
			if (i == -1)
				return (-1);
			res += i;
			continue ;
		}
		res += ft_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}
