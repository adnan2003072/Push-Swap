/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:26:40 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/22 10:49:07 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	ft_clearlst(t_node *head)
{
	t_node	*curr;
	t_node	*next;

	if (!head)
		return ;
	curr = head;
	while (1)
	{
		next = curr->next;
		free(curr);
		if (next == head)
			break ;
		curr = next;
	}
}
