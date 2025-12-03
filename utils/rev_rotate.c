/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:27:33 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 09:35:08 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	rev_rotate(t_stack **s)
{
	if ((*s)->size > 1)
		(*s)->top = (*s)->top->prev;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
