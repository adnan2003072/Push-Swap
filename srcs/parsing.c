/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 08:58:48 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/05 16:51:53 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicated(t_stack **s, int n)
{
	t_node	*tmp;

	tmp = (*s)->top;
	if (tmp)
	{
		while (1)
		{
			if (tmp->data == n)
				return (1);
			tmp = tmp->next;
			if (tmp == (*s)->top)
				break ;
		}
	}
	return (0);
}

static int	parse_split(t_stack **new_stack, char **split)
{
	int		i;
	long	n;

	i = 0;
	while (split[i])
		i++;
	i--;
	while (i >= 0)
	{
		n = ft_atoi(split[i]);
		printf("%ld\n", n);
		if (n != 2147483648 && is_valid_number(split[i]) && !is_duplicated(new_stack, n))
		{
			ft_addnode_front(&((*new_stack)->top), (int)n);
			(*new_stack)->size++;
		}
		else
		{
			free_split(split);
			return (0);
		}
		i--;
	}
	free_split(split);
	return (1);
}

t_stack	*parse_arguments(int ac, char **av)
{
	t_stack	*new_stack;
	char	**split;
	int		i;

	new_stack = init_stack();
	i = ac - 1;
	while (i > 0)
	{
		split = ft_split(av[i], ' ');
		if (!parse_split(&new_stack, split))
		{
			ft_clearlst(new_stack->top);
			free(new_stack);
			return (NULL);
		}
		i--;
	}
	return (new_stack);
}
