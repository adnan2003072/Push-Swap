/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:25:25 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/29 09:27:29 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static void	rotate(t_stack **s)
{
	t_node	*old_top;
	t_node	*old_tail;

	if ((*s)->size <= 1)
		return ;
	old_top = (*s)->top;
	old_tail = (*s)->top->prev;
	old_tail->prev->next = old_top;
	old_tail->next = old_top->next;
	old_tail->prev = old_top;
	old_top->next = old_tail;
	old_top->prev = old_tail->prev;
	(*s)->top = old_tail;
}

void	rotate_r(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
