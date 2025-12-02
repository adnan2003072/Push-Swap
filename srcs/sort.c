/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:36:16 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/02 16:40:50 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static int	max(t_stack **s)
{
	t_node	*next;
	int		max;

	next = (*s)->top;
	max = next->index;
	while (1)
	{
		if (next->index > max)
			max = next->index;
		next = next->next;
		if (next == (*s)->top)
			break ;
	}
	return (max);
}

static int	bits(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n >>= 1;
		i++;
	}
	return (i);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_num;
	int	a_size;
	int	max_bits;
	int	bit;
	int	i;

	max_num = max(a);
	max_bits = bits(max_num);
	bit = 0;
	while (bit < max_bits)
	{
		a_size = (*a)->size;
		i = 0;
		while (i < a_size)
		{
			if ((((*a)->top->index >> bit) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			i++;
		}
		while ((*b)->size > 0)
			push_a(a, b);
		bit++;
	}
}
