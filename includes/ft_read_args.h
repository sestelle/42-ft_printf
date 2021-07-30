/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:37:50 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:57:53 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_ARGS_H
# define FT_READ_ARGS_H

typedef struct	s_args
{
	int			type;
	int			minus;
	int			zero;
	int			width;
	int			precision;
}				t_args;
t_args			*ft_init_args(t_args *args);
char			*ft_read_args(char *itr, t_args *args, va_list ap);
#endif
