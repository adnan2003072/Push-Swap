/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:27:20 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/02 17:07:52 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_node	*new_node;

	if (!a || !b || !*a || (*b)->size == 0)
		return ;
	new_node = ft_newnode((*b)->top->data, (*b)->top->index);
	pop(b);
	if ((*a)->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = (*a)->top;
		new_node->prev = (*a)->top->prev;
		new_node->next->prev = new_node;
		new_node->prev->next = new_node;
	}
	(*a)->top = new_node;
	(*a)->size++;
	write(1, "pa\n", 3);
}
