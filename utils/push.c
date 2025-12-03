/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:27:20 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 11:10:42 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void    pa(t_stack **a, t_stack **b)
{
    t_node *n;

    if (!b || !*b || (*b)->size == 0)
        return;
    n = (*b)->top;
    if ((*b)->size == 1)
        (*b)->top = NULL;
    else
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        (*b)->top = n->next;
    }
    (*b)->size--;
    if ((*a)->size == 0)
    {
        n->next = n;
        n->prev = n;
    }
    else
    {
        n->next = (*a)->top;
        n->prev = (*a)->top->prev;
        n->prev->next = n;
        n->next->prev = n;
    }
    (*a)->top = n;
    (*a)->size++;
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    t_node *n;

    if (!a || !*a || (*a)->size == 0)
        return;

    // take the top node of A
    n = (*a)->top;

    if ((*a)->size == 1)
        (*a)->top = NULL;
    else
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        (*a)->top = n->next;
    }
    (*a)->size--;

    // insert it into B
    if ((*b)->size == 0)
    {
        n->next = n;
        n->prev = n;
    }
    else
    {
        n->next = (*b)->top;
        n->prev = (*b)->top->prev;
        n->prev->next = n;
        n->next->prev = n;
    }
    (*b)->top = n;
    (*b)->size++;

    write(1, "pb\n", 3);
}

// void	pa(t_stack **a, t_stack **b)
// {
// 	t_node	*new_node;
//
// 	if (!a || !b || !*a || (*b)->size == 0)
// 		return ;
// 	new_node = ft_newnode((*b)->top->data, (*b)->top->index);
// 	pop(b);
// 	if ((*a)->size == 0)
// 	{
// 		new_node->next = new_node;
// 		new_node->prev = new_node;
// 	}
// 	else
// 	{
// 		new_node->next = (*a)->top;
// 		new_node->prev = (*a)->top->prev;
// 		new_node->next->prev = new_node;
// 		new_node->prev->next = new_node;
// 	}
// 	(*a)->top = new_node;
// 	(*a)->size++;
// 	write(1, "pa\n", 3);
// }
//
// void	pb(t_stack **a, t_stack **b)
// {
// 	t_node	*new_node;
//
// 	if (!a || !b || !*a || (*a)->size == 0)
// 		return ;
// 	new_node = ft_newnode((*a)->top->data, (*a)->top->index);
// 	pop(a);
// 	if ((*b)->size == 0)
// 	{
// 		new_node->next = new_node;
// 		new_node->prev = new_node;
// 	}
// 	else
// 	{
// 		new_node->next = (*b)->top;
// 		new_node->prev = (*b)->top->prev;
// 		new_node->next->prev = new_node;
// 		new_node->prev->next = new_node;
// 	}
// 	(*b)->top = new_node;
// 	(*b)->size++;
// 	write(1, "pb\n", 3);
// }
