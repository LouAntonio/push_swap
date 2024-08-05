/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:53:57 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/25 12:01:16 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Altera a posição dos dois primeiros nós,
alterando os seus ponteiros (prev e next)*/
void	swap(t_list *stack)
{
	int	a;

	a = stack->value;
	if (stack == NULL)
		return ;
	stack->value = stack->next->value;
	stack->next->value = a;
}

void	sa(t_list **stack)
{
	swap(*stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(*stack);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
