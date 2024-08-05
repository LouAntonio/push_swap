/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:19:57 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/18 12:06:42 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_back(t_list *stack_b, t_list *stack_a)
{
	int		target;
	t_list	*cur_a;

	while (stack_b)
	{
		target = INT_MAX;
		cur_a = stack_a;
		while (cur_a)
		{
			if (cur_a->value > stack_b->value)
			{
				if (cur_a->value < target)
					target = cur_a->value;
			}
			cur_a = cur_a->next;
		}
		if (target == INT_MAX)
			target = min_node_v(stack_a);
		stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	prep_to_push_b(t_list **stack_a, t_list **stack_b)
{
	int	cheapest;

	set_target(*stack_a, *stack_b);
	set_coust(*stack_a, *stack_b);
	cheapest = get_cheapest(*stack_a);
	get_ready(stack_a, stack_b, cheapest);
	if (!is_on_top(*stack_a, cheapest))
		to_top_a(stack_a, cheapest);
	if (!is_on_top(*stack_b, get_target(*stack_a, cheapest)))
		to_top_b(stack_b, get_target(*stack_a, cheapest));
	pb(stack_a, stack_b);
}

void	prep_to_push_a(t_list **stack_a, t_list **stack_b)
{
	int	cheapest;

	set_target_back(*stack_b, *stack_a);
	set_coust(*stack_b, *stack_a);
	cheapest = get_cheapest(*stack_b);
	get_ready(stack_b, stack_a, cheapest);
	if (!is_on_top(*stack_b, cheapest))
		to_top_b(stack_b, cheapest);
	if (!is_on_top(*stack_a, get_target(*stack_b, cheapest)))
		to_top_a(stack_a, get_target(*stack_b, cheapest));
	pa(stack_a, stack_b);
}

int	set_coust_if_dif(t_list *a, t_list *b, t_list *t)
{
	int	qttmoves;
	int	i;
	int	i2;

	qttmoves = 0;
	i = node_index(a, t->value);
	i2 = node_index(b, t->target);
	if (on_top(a, t->value))
		qttmoves += i;
	else
		qttmoves += stack_len(a) - i;
	if (on_top(b, t->target))
		qttmoves += i2;
	else
		qttmoves += stack_len(b) - i2;
	return (qttmoves);
}

int	set_coust_if_t_b(t_list *a, t_list *b, t_list *t)
{
	int	qttmoves;
	int	qttmoves2;
	int	i;
	int	i2;

	qttmoves = 0;
	i = node_index(a, t->value);
	i2 = node_index(b, t->target);
	if (on_top(a, t->value) && on_top(b, t->target))
	{
		qttmoves = i;
		qttmoves2 = i2;
		if (qttmoves2 > qttmoves)
			qttmoves = qttmoves2;
	}
	else if (!on_top(a, t->value) && !on_top(b, t->target))
	{
		qttmoves = stack_len(a) - i;
		qttmoves2 = stack_len(b) - i2;
		if (qttmoves2 > qttmoves)
			qttmoves = qttmoves2;
	}
	else
		qttmoves = set_coust_if_dif(a, b, t);
	return (qttmoves);
}
