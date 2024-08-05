/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:51:48 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/16 14:11:27 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_list *stack)
{
	int		len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	node_index(t_list *stack, int node)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == node)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

t_list	*last_node(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_list	*max_node(t_list *stack)
{
	long	max;
	t_list	*max_node;

	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
