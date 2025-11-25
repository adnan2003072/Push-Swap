/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:27:20 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/25 12:50:11 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_node	*top_b;
	t_node	*new_node;

	if (!a || !b || !*a || !*b)
		return ;
	top_b = (*b)->top;
	new_node = ft_newnode((*a)->top->data);
	pop(a);
	if (!top_b)
	{
		top_b = new_node;
		top_b->next = top_b;
		top_b->prev = top_b;
		return ;
	}
	new_node->next = top_b->next;
	new_node->prev = top_b->prev;
	top_b->prev = new_node;
	top_b = new_node;
	(*b)->size++;
	write(1, "pb\n", 3);
}
