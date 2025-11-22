/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:42:30 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/22 15:47:11 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	swap_a(t_stack **a)
{
	t_node	*top;
	t_node	*second;
	t_node	*tail;

	if (!*a || (*a)->size < 2)
		return ;
	top = (*a)->top;
	second = top->next;
	tail = top->prev;
	top->next = second->next;
	top->prev = second;
	second->next = top;
	second->prev = tail;
	tail->next = second;
	if (top->next != top)
		top->next->prev = top;
	top = second;
    write(1, "sa\n", 3);
}
