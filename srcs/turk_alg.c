/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:53:04 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/25 15:14:01 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target(t_list *stack_a, t_list *stack_b)
{
	int		target;
	t_list	*cur_b;

	while (stack_a)
	{
		target = INT_MIN;
		cur_b = stack_b;
		while (cur_b)
		{
			if (cur_b->value < stack_a->value)
				if (cur_b->value > target)
					target = cur_b->value;
			cur_b = cur_b->next;
		}
		if (target == INT_MIN)
			target = max_node_v(stack_b);
		stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	set_coust(t_list *stack_a, t_list *stack_b)
{
	int		qttmoves;
	int		index;
	int		index2;
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		qttmoves = 0;
		index = node_index(stack_a, tmp->value);
		index2 = node_index(stack_b, tmp->target);
		qttmoves = set_coust_if_t_b(stack_a, stack_b, tmp);
		tmp->coust = qttmoves;
		tmp = tmp->next;
	}
}

void	get_ready(t_list **stack_a, t_list **stack_b, int cheapest)
{
	int	target;

	target = get_target(*stack_a, cheapest);
	while (!is_on_top(*stack_a, cheapest) && !is_on_top(*stack_b, target))
	{
		if (on_top(*stack_a, cheapest) && on_top(*stack_b, target))
			rr(stack_a, stack_b);
		else if (!on_top(*stack_a, cheapest) && !on_top(*stack_b, target))
			rrr(stack_a, stack_b);
		else
			break ;
	}
}

void	sort_a(t_list **stack_a)
{
	if (last_node(*stack_a)->value < (*stack_a)->value)
		while (last_node(*stack_a)->value < (*stack_a)->value)
			rra(stack_a);
	else if (last_node(*stack_a)->value > (*stack_a)->value)
		while (last_node(*stack_a)->value > (*stack_a)->value)
			ra(stack_a);
}

void	turk_alg(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_len(*stack_a) >= 3)
		prep_to_push_b(stack_a, stack_b);
	while (stack_len(*stack_b) != 0)
		prep_to_push_a(stack_a, stack_b);
	sort_a(stack_a);
}
