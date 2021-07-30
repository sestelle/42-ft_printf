/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:34:37 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:51:05 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stddef.h"
# include "unistd.h"
# include "stdlib.h"

int		ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int		ft_putstr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_uitoa(unsigned int n);
#endif
