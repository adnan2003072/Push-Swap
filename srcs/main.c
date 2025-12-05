/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:35:56 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/05 16:54:02 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
}

void	print_cdll(t_node **head, int size)
{
	t_node	*tmp;

	if (!head || !*head)
	{
		printf("Empty CDLL !\n");
		return ;
	}
	printf("Stack of size : %d\n", size);
	tmp = *head;
	while (1)
	{
		printf("%d", tmp->data);
		tmp = tmp->next;
		if (tmp == *head)
			break ;
		printf("<->");
	}
	printf("\n");
}

// int	main(int ac, char *av[])
// {
// 	t_stack	*a;
// 	t_stack	*b;
//
// 	if (ac == 1)
// 		return (1);
// 	a = parse_arguments(ac, av);
// 	if (!a)
// 	{
// 		ft_perror();
// 		return (1);
// 	}
// 	print_cdll(&(a->top), a->size);
// 	b = init_stack();
// 	if (!is_sorted(a))
// 		sort(&a, &b);
// 	if (a)
// 	{
// 		ft_clearlst(a->top);
// 		free(a);
// 	}
// 	if (b)
// 	{
// 		ft_clearlst(b->top);
// 		free(b);
// 	}
// 	return (0);
// }

int main(void)
{
	printf("%ld\n", ft_atoi("2147483648"));
	return 0;
}
