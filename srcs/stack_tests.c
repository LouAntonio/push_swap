/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:48:18 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/16 17:20:37 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_nodes(t_list *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		printf("%d -> ", i++);
		printf("%d -> ", stack->value);
		printf("%d -> ", stack->target);
		printf("%d ->\n", stack->coust);
		stack = stack->next;
	}
}
