/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:27:20 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/02 17:08:11 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_node	*new_node;

	if (!a || !b || !*a || (*a)->size == 0)
		return ;
	new_node = ft_newnode((*a)->top->data, (*a)->top->index);
	pop(a);
	if ((*b)->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = (*b)->top;
		new_node->prev = (*b)->top->prev;
		new_node->next->prev = new_node;
		new_node->prev->next = new_node;
	}
	(*b)->top = new_node;
	(*b)->size++;
	write(1, "pb\n", 3);
}
