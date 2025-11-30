/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:15:40 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/30 10:18:22 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	if (len > 0)
	{
		i = 0;
		while (i < len)
		{
			res[i] = s[i];
			i++;
		}
	}
	res[len] = '\0';
	return (res);
}
