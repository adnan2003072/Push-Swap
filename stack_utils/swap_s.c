/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:46:34 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/25 12:00:53 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static void	swap(t_stack **s)
{
	t_node	*top;
	t_node	*second;
	t_node	*tail;

	if (!*s || (*s)->size < 2)
		return ;
	top = (*s)->top;
	second = top->next;
	tail = top->prev;
	if ((*s)->size == 2)
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
	(*s)->top = second;
}

void	swap_s(t_stack **a, t_stack **b)
{
	if (!a || !b || !*a || !*b)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
