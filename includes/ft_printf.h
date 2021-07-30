/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:29:53 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:57:27 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "libft.h"
# include "stddef.h"
# include "ft_read_args.h"
# include "ft_conversion.h"

int		ft_printf(const char *format, ...);
#endif
