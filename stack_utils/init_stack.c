/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:10:11 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/21 10:31:19 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

t_list	*init_stack(int ac, char *av[])
{
	t_list	*new_stack;
	int		*content;
	int		i;

	new_stack = NULL;
	if (ac == 0)
		return (NULL);
	i = ac - 1;
	while (i > 0)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(new_stack);
			return (NULL);
		}
		*content = ft_atoi(av[i]);
		ft_lstadd_front(&new_stack, (void *)content);
		i--;
	}
	return (new_stack);
}
