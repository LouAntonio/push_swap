/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:54:23 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/17 09:32:10 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Remove o primeiro elemento de uma stack e o coloca no topo da outra,
editando os seus ponteiros*/
void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*to_push;

	if (stack_src == NULL)
		return ;
	to_push = *stack_src;
	*stack_src = (*stack_src)->next;
	to_push->next = *stack_dst;
	*stack_dst = to_push;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
