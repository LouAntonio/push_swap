/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:11:52 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/18 12:09:30 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_node_v(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	min_node_v(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	is_on_top(t_list *stack, int node)
{
	if (stack->value == node)
		return (1);
	return (0);
}

t_list	*min_node(t_list *stack)
{
	long	min;
	t_list	*min_node;

	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

char	**int_to_arr(char **av, int ac)
{
	char	**mat;
	int		i;

	i = 0;
	mat = (char **)malloc(sizeof(char *) * ac);
	while (--ac)
	{
		mat[i] = ft_strdup(av[i + 1]);
		i++;
	}
	mat[i] = NULL;
	return (mat);
}
