/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:35:56 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/02 18:05:57 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
}

void	print_node(t_node *node)
{
	printf("node: %d\n", node->data);
	printf("\tprev: %d\n", node->prev->data);
	printf("\tnext: %d\n", node->next->data);
}

void print_cdll(t_node **head)
{
    t_node  *tmp;

    if (!head || !*head)
    {
        printf("Empty CDLL !\n");
        return ;
    }
    tmp = *head;
    while (1)
    {
        printf("%d", tmp->data); 
        tmp = tmp->next;
        if (tmp == *head)
            break; 
        printf("<->");
    }
    printf("\n");
}

int	check_circularity(t_node **head, int size)
{
	t_node	*fast_next;
	t_node	*slow_next;
	t_node	*fast_prev;
	t_node	*slow_prev;
	int		i;

	if (!head || !*head)
		return (0);
	fast_next = *head;
	slow_next  = *head;
	fast_prev = (*head)->prev;
	slow_prev = (*head)->prev;
	i = 0;
	while (i < size + 1 && slow_next ->next)
	{
		fast_next = fast_next->next->next;
		slow_next  = slow_next ->next;
		fast_prev = fast_prev->prev->prev;
		slow_prev = slow_prev->prev;
		if (slow_next  == fast_next && fast_prev == slow_prev)
			return (1);
		i++;
	}
	return (0);
}

void	assign_indexes(t_stack **s)
{
	t_node	*curr;
	t_node	*other;
	int		index;

	if ((*s)->size < 2)
		return ;
	curr = (*s)->top;
	while (1)
	{
		index= 0;
		other = (*s)->top;
		while (1)
		{
			if (other->data < curr->data)
				index += 1;
			other = other->next;
			if (other == (*s)->top)
				break ;
		}
		curr->index = index;
		curr = curr->next;
		if (curr == (*s)->top)
			break ;
	}
}

int main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (1);
	a = parse_arguments(ac, av);
	b = init_stack();
	assign_indexes(&a);
	radix_sort(&a, &b);
	if (a)
	{
		ft_clearlst(a->top);
		free(a);
	}
	if (b)
	{
		ft_clearlst(b->top);
		free(b);
	}
	return (0);
}
