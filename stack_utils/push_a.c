/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:27:20 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/25 12:50:19 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_node	*top_a;
	t_node	*new_node;

	if (!a || !b || !*a || !*b)
		return ;
	top_a = (*a)->top;
	new_node = ft_newnode((*b)->top->data);
	pop(b);
	if (!top_a)
	{
		top_a = new_node;
		top_a->next = top_a;
		top_a->prev = top_a;
		return ;
	}
	new_node->next = top_a->next;
	new_node->prev = top_a->prev;
	top_a->prev = new_node;
	top_a = new_node;
	(*a)->size++;
	write(1, "pa\n", 3);
}
