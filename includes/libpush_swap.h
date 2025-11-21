/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:11:30 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/21 11:44:57 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

// linked lists functions
t_list	*ft_lstnew(int n);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

// stack operations
t_list	*init_stack(int ac, char *av[]);
void	swap_a(t_list *a);
void	swap_b(t_list *a);
void	swap_s(t_list *a, t_list *b);
t_list	*push_a(t_list *a, t_list *b);
t_list	*push_b(t_list *a, t_list *b);
void	rotate_a(t_list *a);
void	rotate_b(t_list *b);
void	rotate_r(t_list *a, t_list *b);
void	reverse_rotate_a(t_list *a);
void	reverse_rotate_b(t_list *b);
void	reverse_rotate_r(t_list *a, t_list *b);

#endif
