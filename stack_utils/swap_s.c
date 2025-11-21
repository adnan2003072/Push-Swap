/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:41:37 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/21 11:44:29 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	swap_s(t_list *a, t_list *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = (int *)a->content;
	(a->next)->content = a->content;
	a->content = tmp;
	tmp = (int *)b->content;
	(b->next)->content = b->content;
	b->content = tmp;
	write(1, "ss\n", 3);
}
