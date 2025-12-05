/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:51:09 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/05 16:53:29 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"
#include <stdio.h>

static int	get_sign(char c, size_t *i)
{
	if (c == '-' || c == '+')
	{
		*i += 1;
		if (c == '-')
			return (-1);
	}
	return (1);
}

static int	check_overflow(long res, int digit, int sign)
{
	int	max;
	int	min;

	min = (1 << 31);
	max = ~min;
	if ((sign == 1 && (res > (max - digit) / 10))
		|| (sign == -1 && (-res < (min + digit) / 10)))
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;
	int		digit;
	size_t	i;
	int		int_max;

	int_max = ~(1 << 31);
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	sign = get_sign(nptr[i], &i);
	res = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (check_overflow(res, digit, sign))
			return ((long)int_max + 1);
		res = res * 10 + digit;
		i++;
	}
	return (sign * res);
}
