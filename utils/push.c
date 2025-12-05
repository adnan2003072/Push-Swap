/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:27:20 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/05 12:54:54 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static t_node	*detach_a_top(t_stack **a)
{
	t_node	*a_top;

	a_top = (*a)->top;
	if ((*a)->size == 1)
		(*a)->top = NULL;
	else
	{
		a_top->prev->next = a_top->next;
		a_top->next->prev = a_top->prev;
		(*a)->top = a_top->next;
	}
	(*a)->size--;
	return (a_top);
}

static t_node	*detach_b_top(t_stack **b)
{
	t_node	*b_top;

	b_top = (*b)->top;
	if ((*b)->size == 1)
		(*b)->top = NULL;
	else
	{
		b_top->prev->next = b_top->next;
		b_top->next->prev = b_top->prev;
		(*b)->top = b_top->next;
	}
	(*b)->size--;
	return (b_top);
}

void	pa(t_stack **a, t_stack **b)
{
	t_node	*b_top;

	if (!b || !*b || (*b)->size == 0)
		return ;
	b_top = detach_b_top(b);
	if ((*a)->size == 0)
	{
		b_top->next = b_top;
		b_top->prev = b_top;
	}
	else
	{
		b_top->next = (*a)->top;
		b_top->prev = (*a)->top->prev;
		b_top->prev->next = b_top;
		b_top->next->prev = b_top;
	}
	(*a)->top = b_top;
	(*a)->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_node	*a_top;

	if (!a || !*a || (*a)->size == 0)
		return ;
	a_top = detach_a_top(a);
	if ((*b)->size == 0)
	{
		a_top->next = a_top;
		a_top->prev = a_top;
	}
	else
	{
		a_top->next = (*b)->top;
		a_top->prev = (*b)->top->prev;
		a_top->prev->next = a_top;
		a_top->next->prev = a_top;
	}
	(*b)->top = a_top;
	(*b)->size++;
	write(1, "pb\n", 3);
}
