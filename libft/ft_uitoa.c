/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:35:13 by sestelle          #+#    #+#             */
/*   Updated: 2021/01/19 12:51:21 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(unsigned int *n)
{
	int		sign;

	sign = 0;
	if (*n < 0)
	{
		*n *= -1;
		sign = 1;
	}
	return (sign);
}

static int		ft_size(unsigned int n)
{
	int		size;

	size = 0;
	while (n /= 10)
	{
		size += 1;
	}
	return (size);
}

static char		*ft_fill(char *str, int size, unsigned int n, int sign)
{
	str[--size] = '\0';
	while (size--)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char			*ft_uitoa(unsigned int n)
{
	int		size;
	int		sign;
	char	*str;

	if (n < 0)
		return (ft_strdup("-1"));
	size = ft_size(n) + 2;
	sign = ft_sign(&n);
	size += sign;
	if (!(str = (char *)malloc(size * sizeof(char))))
		return (NULL);
	str = ft_fill(str, size, n, sign);
	return (str);
}
