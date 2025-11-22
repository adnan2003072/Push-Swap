/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:44:17 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/22 15:24:57 by abouzkra         ###   ########.fr       */
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

void print_cdll(t_node **head)
{
    t_node  *tmp;

    if (!head)
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

int main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	if (check_numbers(ac, av) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	t_stack	*a;
	a = init_stack(ac, av);
	print_cdll(&(a->top));
	swap_a(&a);
	print_cdll(&(a->top));
	ft_clearlst(a->top);
	free(a);
	return (0);
}
