/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 08:58:48 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/30 11:37:45 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

void	ft_perror(void)
{
	write(1, "Error\n", 6);
}

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

static int	parse_split(t_stack **new_stack, char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (is_valid_number(split[i]))
			ft_addnode_front(&((*new_stack)->top), ft_atoi(split[i]));
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
			ft_perror();
			ft_clearlst(new_stack->top);
			free(new_stack);
		}
		i--;
	}
	return (new_stack);
}
