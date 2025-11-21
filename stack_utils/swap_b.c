/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:40:07 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/21 11:42:20 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	swap_b(t_list *b)
{
	int	tmp;

	if (!b)
		return ;
	tmp = (int *)b->content;
	(b->next)->content = b->content;
	b->content = tmp;
	write(1, "sb\n", 3);
}
