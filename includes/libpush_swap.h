/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:11:30 by abouzkra          #+#    #+#             */
/*   Updated: 2025/11/30 11:35:23 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
int		ft_isdigit(int c);
t_node	*ft_newnode(int data);
void	ft_clearlst(t_node *head);
t_node	*ft_addnode_front(t_node **head, int data);
t_stack	*parse_arguments(int ac, char **av);

t_stack	*init_stack(void);
void	pop(t_stack **s);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_s(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_r(t_stack **a, t_stack **b);
void	rev_rotate_a(t_stack **a);
void	rev_rotate_b(t_stack **b);
void	rev_rotate_r(t_stack **a, t_stack **b);

#endif
