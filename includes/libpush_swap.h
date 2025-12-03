/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:11:30 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 12:26:56 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	ft_perror(void);
t_node	*ft_newnode(int data, int index);
void	ft_clearlst(t_node *head);
t_node	*ft_addnode_front(t_node **head, int data, int index);
t_stack	*parse_arguments(int ac, char **av);

int		find_max(t_node *head);
int		find_min(t_node *head);
void 	print_cdll(t_node **head);
void	cheap_pb(t_stack **a, t_stack **b)
void	sort3(t_stack **a);
void	sort5(t_stack **a, t_stack **b);

t_stack	*init_stack(void);
void	pop(t_stack **s);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
