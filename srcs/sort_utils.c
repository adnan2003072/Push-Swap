/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:32:03 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/04 22:18:33 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

t_node	*find_max_node(t_node *head)
{
    t_node *curr = head;
    t_node *max_node = head;
    int max = head->data;

    curr = curr->next;
    while (curr != head)
    {
        if (curr->data > max)
        {
            max = curr->data;
            max_node = curr;
        }
        curr = curr->next;
    }
    return max_node;
}

t_node	*find_min_node(t_node *head)
{
    t_node *curr = head;
    t_node *min_node = head;
    int min = head->data;

    curr = curr->next;
    while (curr != head)
    {
        if (curr->data < min)
        {
            min = curr->data;
            min_node = curr;
        }
        curr = curr->next;
    }
    return min_node;
}

int	get_pos(t_node *head, int data)
{
	t_node	*next;
	int		i;

	next = head;
	i = 0;
	while (1)
	{
		if (next->data == data)
			return (i);
		i++;
		next = next->next;
		if (next == head)
			break ;
	}
	return (-1);
}

int is_sorted(t_stack *a)
{
    t_node *cur;

    if (!a || a->size <= 1)
        return (1);
    cur = a->top;
    while (cur->next != a->top)
    {
        if (cur->data > cur->next->data)
            return (0);
        cur = cur->next;
    }
    return (1);
}

