/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:57:09 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/16 18:29:24 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_target(t_list *stack, int node)
{
	while (stack)
	{
		if (stack->value == node)
			return (stack->target);
		stack = stack->next;
	}
	return (stack->target);
}

void	to_top_a(t_list **stack, int node)
{
	while (!is_on_top(*stack, node))
	{
		if (on_top(*stack, node))
			ra(stack);
		else
			rra(stack);
	}
}

void	to_top_b(t_list **stack, int node)
{
	while (!is_on_top(*stack, node))
	{
		if (on_top(*stack, node))
			rb(stack);
		else
			rrb(stack);
	}
}

int	on_top(t_list *stack, int node)
{
	int	index;
	int	middle;

	index = node_index(stack, node);
	middle = stack_len(stack) / 2;
	if (index <= middle)
		return (1);
	return (0);
}

int	get_cheapest(t_list *stack)
{
	int	cheapest;
	int	cheapest_value;

	cheapest = INT_MAX;
	while (stack)
	{
		if (stack->coust < cheapest)
		{
			cheapest = stack->coust;
			cheapest_value = stack->value;
		}
		stack = stack->next;
	}
	return (cheapest_value);
}
