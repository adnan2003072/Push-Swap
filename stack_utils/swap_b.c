/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:42:30 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/25 11:58:26 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	swap_b(t_stack **b)
{
	t_node	*top;
	t_node	*second;
	t_node	*tail;

	if (!*b || (*b)->size < 2)
		return ;
	top = (*b)->top;
	second = top->next;
	tail = top->prev;
	if ((*b)->size == 2)
	{
		top->next = second;
		second->prev = top;
	}
	else
	{
		second->next->prev = top;
		second->prev = top->prev;
		top->next = second->next;
		tail->next = second;
	}
	top->prev = second;
	second->next = top;
	(*b)->top = second;
    write(1, "sb\n", 3);
}
