/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:48:49 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/21 11:41:20 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	swap_a(t_list *a)
{
	int	tmp;

	if (!a)
		return ;
	tmp = (int *)a->content;
	(a->next)->content = a->content;
	a->content = tmp;
	write(1, "sa\n", 3);
}
