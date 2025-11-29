/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:27:33 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/29 17:29:29 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	rev_rotate_r(t_stack **a, t_stack **b)
{
	if ((*a)->size > 1)
		(*a)->top = (*a)->top->prev;
	if ((*b)->size > 1)
		(*b)->top = (*b)->top->prev;
	write(1, "rrr\n", 4);
}
