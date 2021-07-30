/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:40:15 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:57:37 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args		*ft_init_args(t_args *args)
{
	args->minus = 0;
	args->zero = 0;
	args->width = 0;
	args->precision = -1;
	args->type = 0;
	return (args);
}
