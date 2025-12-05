/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:32:03 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/05 12:08:26 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

t_node	*find_max_node(t_node *head)
{
	t_node	*curr;
	t_node	*max_node;
	int		max;

	max_node = head;
	curr = head->next;
	max = head->data;
	while (curr != head)
	{
		if (curr->data > max)
		{
			max = curr->data;
			max_node = curr;
		}
		curr = curr->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_node *head)
{
	t_node	*curr;
	t_node	*min_node;
	int		min;

	min_node = head;
	curr = head->next;
	min = head->data;
	while (curr != head)
	{
		if (curr->data < min)
		{
			min = curr->data;
			min_node = curr;
		}
		curr = curr->next;
	}
	return (min_node);
}

void	sort3(t_stack **a)
{
	int	max;

	if ((*a)->size > 3)
		return ;
	max = find_max_node((*a)->top)->data;
	if ((*a)->top->data == max)
		ra(a);
	else if ((*a)->top->next->data == max)
		rra(a);
	if ((*a)->top->data > (*a)->top->next->data)
		sa(a);
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size <= 1)
		return (1);
	cur = a->top;
	while (cur->next != a->top)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}
