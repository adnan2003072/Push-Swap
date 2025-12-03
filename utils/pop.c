/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:13:18 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/25 12:49:04 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	pop(t_stack **s)
{
	t_node	*old_top;
	t_node	*new_top;

	if (!s || !*s || (*s)->size == 0)
		return ;
	(*s)->size--;
	if ((*s)->size == 0)
	{
		free((*s)->top);
		(*s)->top = NULL;
		return ;
	}
	old_top = (*s)->top;
	new_top = old_top->next;
	new_top->prev = old_top->prev;
	old_top->prev->next = new_top;
	free(old_top);
	(*s)->top = new_top;
}
