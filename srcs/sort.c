/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:36:24 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/04 22:19:01 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libpush_swap.h"

static t_cost find_best_to_insert(t_stack **a, t_stack **b)
{
	t_node	*b_node;
	t_cost	cost;
	t_cost	best_cost;

	b_node = (*b)->top->next;
	best_cost = cost_to_insert(a, b, (*b)->top);
	while (1)
	{
		cost = cost_to_insert(a, b, b_node);
		if (cost.total < best_cost.total)
		{
			best_cost = cost;
			best_cost.target = b_node;
		}
		b_node = b_node->next;
		if (b_node == (*b)->top)
			break ;
	}
	return (best_cost);
}

static void	optimal_moves(t_stack **a, t_stack **b, t_cost cost)
{
	if (cost.a_dir == 1 &&  cost.b_dir == 1)
	{
		while (cost.a_moves > 0 && cost.b_moves > 0)
		{
			rr(a, b);
			cost.a_moves--;
			cost.b_moves--;
		}
	}
	else if (cost.a_dir == 1 &&  cost.b_dir == 1)
	{
		while (cost.a_moves > 0 && cost.b_moves > 0)
		{
			rrr(a, b);
			cost.a_moves--;
			cost.b_moves--;
		}
	}
	while (cost.a_moves > 0)
	{
		if (cost.a_dir == 1)
			ra(a);
		else
			rra(a);
		cost.a_moves--;
	}
	while (cost.b_moves > 0)
	{
		if (cost.b_dir == 1)
			rb(b);
		else
			rrb(b);
		cost.b_moves--;
	}
}

static void    rotate_min_to_top(t_stack **a, t_node *min)
{
    t_node  *cur;
    int     dist_forward = 0;
    int     dist_backward;

    if (!a || !*a || (*a)->size <= 1)
        return;
    cur = (*a)->top;
    while (cur != min)
    {
        cur = cur->next;
        dist_forward++;
    }
    dist_backward = (*a)->size - dist_forward;
    if (dist_forward <= dist_backward)
        while ((*a)->top != min)
            ra(a);
    else
        while ((*a)->top != min)
            rra(a);
}

void	sort(t_stack **a, t_stack **b)
{
	int		median;
	t_cost	best_cost;

	median = find_median(*a);
	while ((*a)->size > 3)
	{
		pb(a, b);
		if ((*b)->top->data > median)
			rb(b);
	}
	sort3(a);
	while ((*b)->size)
	{
		best_cost = find_best_to_insert(a, b);
		optimal_moves(a, b, best_cost);
		pa(a, b);
	}
	rotate_min_to_top(a, find_min_node((*a)->top));
}
