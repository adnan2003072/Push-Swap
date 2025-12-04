/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:48:04 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/04 21:52:55 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static t_node	*find_target_pos(t_stack **a, t_node *b_node)
{
	t_node	*next;
	t_node	*min_a;
	t_node	*max_a;

	next = (*a)->top;
	while (1)
	{
		if (b_node->data > next->data && b_node->data < next->next->data)
			break ;
		next = next->next;
		if (next == (*a)->top)
			break ;
	}
	min_a = find_min_node((*a)->top);
	max_a = find_max_node((*a)->top);
	if (b_node->data < min_a->data || b_node->data > max_a->data)
		next = max_a;
	return (next);
}

static void	compute_rotations_a(t_stack **a, t_node *target, t_cost *cost)
{
	t_node	*tmp;
	int		dist_forward;

	tmp = (*a)->top;
	dist_forward = 0;
	while (tmp != target->next)
	{
		tmp = tmp->next;
		dist_forward++;
	}
	if (dist_forward <= (*a)->size - dist_forward)
	{
		cost->a_moves = dist_forward;
		cost->a_dir = 1;
	}
	else
	{
		cost->a_moves = (*a)->size - dist_forward;
		cost->a_dir = -1;
	}
}

static void	compute_rotations_b(t_stack **b, t_node *target, t_cost *cost)
{
	t_node	*tmp;
	int		dist_forward;

	tmp = (*b)->top;
	dist_forward = 0;
	while (tmp != target)
	{
		tmp = tmp->next;
		dist_forward++;
	}
	if (dist_forward <= (*b)->size - dist_forward)
	{
		cost->b_moves = dist_forward;
		cost->b_dir = 1;
	}
	else
	{
		cost->b_moves = (*b)->size - dist_forward;
		cost->b_dir = -1;
	}
}

t_cost	cost_to_insert(t_stack **a, t_stack **b, t_node *b_node)
{
	t_cost	cost;
	t_node	*target_a;

	cost = (t_cost){0, 0, 0, 0, 0, NULL};
	target_a = find_target_pos(a, b_node);
	compute_rotations_a(a, target_a, &cost);
	compute_rotations_b(b, b_node, &cost);
	if (cost.a_dir == cost.b_dir)
	{
		if (cost.a_moves > cost.b_moves)
			cost.total = cost.a_moves;
		else
			cost.total = cost.b_moves;
	}
	else
		cost.total = cost.a_moves + cost.b_moves;
	return (cost);
}
