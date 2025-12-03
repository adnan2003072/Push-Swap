/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:32:03 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 13:12:36 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

int	find_max(t_node *head)
{
	t_node	*next;
	int		max;

	max = head->index;
	next = head->next;
	while (1)
	{
		if (next->index > max)
			max = next->index;
		next = next->next;
		if (next == head)
			break ;
	}
	return (max);
}

int	find_min(t_node *head)
{
	t_node	*next;
	int		min;

	min = head->index;
	next = head->next;
	while (1)
	{
		if (next->index < min)
			min = next->index;
		next = next->next;
		if (next == head)
			break ;
	}
	return (min);
}

int	get_pos(t_node *head, int index)
{
	t_node	*next;
	int		i;

	next = head;
	i = 0;
	while (1)
	{
		if (next->index == index)
			return (i);
		i++;
		next = next->next;
		if (next == head)
			break ;
	}
	return (-1);
}

void	cheap_rotation(t_stack **a, t_stack **b)
{
	int	min;
	int pos;

	min = find_min((*a)->top);
	pos = get_pos((*a)->top, min);
	if (pos > (*a)->size / 2)
		while ((*a)->top->index != min)
			rra(a);
	else
		while ((*a)->top->index != min)
			ra(a);
}

int	is_sorted(t_stack **a)
{
	t_node	*top;

	top = (*a)->top;
	while (1)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
		if (top == (*a)->top)
			break ;
	}
	return (1);
}
