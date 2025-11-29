/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:35:56 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/29 09:29:43 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

int	check_numbers(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

int main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	if (check_numbers(ac, av) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}

	t_stack	*a = init_stack(ac, av);
	t_stack	*b = init_stack(ac, av);

	printf("Stack A:\n");
	print_cdll(&(a->top));
	printf("Stack B:\n");
	print_cdll(&(b->top));
	rotate_r(&a, &b);
	printf("Stack A:\n");
	print_cdll(&(a->top));
	printf("Stack B:\n");
	print_cdll(&(b->top));
	if (check_circularity(&(a->top), a->size))
		printf("YOUR CDLL(%d) IS PERFECTLY CIRCULAR !\n", a->size);
	else
		printf("OOPS !\n");

	ft_clearlst(a->top);
	free(a);
	ft_clearlst(b->top);
	free(b);
	return (0);
}

