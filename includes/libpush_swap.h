/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:11:30 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/04 22:07:54 by abouzkra         ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_cost
{
	int		total;
	int		a_moves;
	int		b_moves;
	int		a_dir;
	int		b_dir;
	t_node	*target;
} t_cost;

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	ft_perror(void);
t_node	*ft_newnode(int data);
void	ft_clearlst(t_node *head);
t_node	*ft_addnode_front(t_node **head, int data);
t_stack	*parse_arguments(int ac, char **av);

void print_cdll(t_node **head, int size);
int is_sorted(t_stack *a);
t_node	*find_max_node(t_node *head);
t_node	*find_min_node(t_node *head);
t_cost	cost_to_insert(t_stack **a, t_stack **b, t_node *b_node);
int		find_median(t_stack *s);
void	sort3(t_stack **a);
void	sort(t_stack **a, t_stack **b);

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
