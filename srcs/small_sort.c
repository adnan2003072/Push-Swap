/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:36:45 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/04 21:54:09 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

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
