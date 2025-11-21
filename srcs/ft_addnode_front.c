/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:36:08 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/22 00:04:31 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

t_node	*ft_addnode_front(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_newnode(data);
	if (!(*head))
	{
		*head = new_node;
		(*head)->next = new_node;
		(*head)->prev = new_node;
	}
	else
	{
		last_node = (*head)->prev;
		new_node->next = *head;
		new_node->prev = last_node;
		(*head)->prev = new_node;
		last_node->next = new_node;
		*head = new_node;
	}
	return (*head);
}
