/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:36:16 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 13:31:45 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	sort3(t_stack **a)
{
	int	max;

	if ((*a)->size != 3)
		return ;
	max = find_max((*a)->top);
	if ((*a)->top->index == max)
		ra(a);
	else if ((*a)->top->next->index == max)
		rra(a);
	if ((*a)->top->index > (*a)->top->next->index)
		sa(a);
}

void	sort5(t_stack **a, t_stack **b)
{
	if ((*a)->size != 5)
		return ;
	cheap_rotation(a, b);
	cheap_roatation(a, b);
	sort3(a);
	if ((*b)->top->index < (*b)->top->next->index)
		rb(b);
	pa(a, b);
	pa(a, b);
}

static void	move_back(t_stack **a, t_stack **b)
{
	while ((*b)->size)
		pa(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	t_node	*target;
	if ((*a)->size <= 3)
	{
		sort3(a);
		return ;
	}
	while ((*a)->size > 3)
	{
		cheap_rotation(a, b);
		pb(a, b);
		if (!is_sorted(a))
		{
			move_back(a, b);
			break ;
		}
	}
	sort3(a);
	while ((*b)->size > 0)
	{
		target = find_target(a, b);
	}
}
