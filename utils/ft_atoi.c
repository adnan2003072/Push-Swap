/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:51:09 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/01 12:58:58 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

int	get_sign(char c, size_t *i)
{
	if (c == '-' || c == '+')
	{
		*i += 1;
		if (c == '-')
			return (-1);
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;
	int		digit;
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	sign = get_sign(nptr[i], &i);
	res = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		res = res * 10 + digit;
		i++;
	}
	return (sign * res);
}
