/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:09:06 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/29 09:24:36 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	rotate_b(t_stack **b)
{
	t_node	*old_top;
	t_node	*old_tail;

	if ((*b)->size <= 1)
		return ;
	old_top = (*b)->top;
	old_tail = (*b)->top->prev;
	old_tail->prev->next = old_top;
	old_tail->next = old_top->next;
	old_tail->prev = old_top;
	old_top->next = old_tail;
	old_top->prev = old_tail->prev;
	(*b)->top = old_tail;
	write(1, "rb\n", 3);
}
