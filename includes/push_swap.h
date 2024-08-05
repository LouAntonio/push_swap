/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:35:21 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/25 16:05:29 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				coust;
	int				target;
	struct s_list	*next;
}	t_list;

/*ERROR CHECK*/
void	free_stack(t_list **stack);
void	free_matrix(char **av);
void	error_free(t_list **stack_a, char **av);
int		sintax_error(char *str_nbr);
int		is_duplicated(t_list *stack, int n);

/*OPERATIONS*/
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*UTILS*/
int		ft_issign(char c);
int		ft_isdigit(char c);
char	*ft_strdup(char *s);
int		ft_strlen(char *str);
char	**ft_split(char *str, char c);
void	ft_exit(void);

/*STACK INITIALIZATION*/
void	init_a(t_list **stack_a, char **av);
void	add_node(t_list **stack, int n);

/*TESTS*/
void	print_nodes(t_list *stack);

/*STACK & SORTING UTILS*/
int		is_sorted(t_list *stack);
int		stack_len(t_list *stack);
int		node_index(t_list *stack, int node);
t_list	*last_node(t_list *stack);
t_list	*max_node(t_list *stack);
int		get_target(t_list *stack, int node);
void	to_top_a(t_list **stack, int node);
void	to_top_b(t_list **stack, int node);
int		on_top(t_list *stack, int node);
int		get_cheapest(t_list *stack);
int		max_node_v(t_list *stack);
int		min_node_v(t_list *stack);
int		is_on_top(t_list *stack, int node);
t_list	*min_node(t_list *stack);
char	**int_to_arr(char **av, int ac);

/*SORTING*/
void	sort_three(t_list **stack);
void	sort_five_or_less(t_list **a, t_list **b);
void	set_target(t_list *stack_a, t_list *stack_b);
void	set_target_back(t_list *stack_b, t_list *stack_a);
void	set_coust(t_list *stack_a, t_list *stack_b);
void	get_ready(t_list **stack_a, t_list **stack_b, int cheapest);
void	sort_a(t_list **stack_a);
void	prep_to_push_b(t_list **stack_a, t_list **stack_b);
void	prep_to_push_a(t_list **stack_a, t_list **stack_b);
int		set_coust_if_t_b(t_list *a, t_list *b, t_list *t);
int		set_coust_if_dif(t_list *a, t_list *b, t_list *t);
void	turk_alg(t_list **stack_a, t_list **stack_b);

#endif