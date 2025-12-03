/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:35:56 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 12:19:32 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"
#include <stdio.h>

void	ft_perror(void)
{
	write(2, "Error\n", 6);
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

int check_circularity(t_node **head)
{
    t_node *tmp;

    if (!head || !*head)
        return 0;
    tmp = (*head)->next;
    while (tmp && tmp != *head)
        tmp = tmp->next;

    if (tmp != *head)
        return 0;
    tmp = (*head)->prev;
    while (tmp && tmp != *head)
        tmp = tmp->prev;

    if (tmp != *head)
        return 0;
    return 1;
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
	if (!a)
	{
		ft_perror();
		return (1);
	}
	b = init_stack();
	assign_indexes(&a);
	sort5(&a, &b);
	print_cdll(&(a->top));
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
