/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:32:16 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/30 11:32:27 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	free_split(char **res)
{
	char	**tmp;

	tmp = res;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(res);
}
