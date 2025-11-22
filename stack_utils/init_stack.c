/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:33:51 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/22 11:30:52 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

t_stack	*init_stack(int ac, char *av[])
{
	t_stack	*new_stack;
	int		i;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->size = 0;
	i = ac - 1;
	while (i > 0)
	{
		ft_addnode_front(&(new_stack->top), ft_atoi(av[i]));
		i--;
	}
	new_stack->size = ac;
	return (new_stack);
}
