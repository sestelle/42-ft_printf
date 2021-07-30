/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:51:54 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:57:49 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H

int		ft_conversion(va_list ap, t_args *args);
int		ft_print(t_args *args, int len);
int		ft_precision(char *str, int precision);
int		ft_width(int width, int min, int is_zero);
int		ft_put_char(t_args *args, va_list ap);
int		ft_put_str(t_args *args, va_list ap);
int		ft_put_str_helper(t_args *args, char *str);
int		ft_put_int(t_args *args, va_list ap);
int		ft_put_percentage(t_args *args);
int		ft_put_x(t_args *args, va_list ap);
int		ft_put_pointer(t_args *args, va_list ap);
int		ft_put_uint(t_args *args, va_list ap);
#endif
