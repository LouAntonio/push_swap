/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:15:55 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/25 11:57:29 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Se o primeiro for o maior, mandar para a última posição (ra)
se o segundo for o maior, o último se torna o primeiro (rra)
se o primeiro for maior que o segundo, trocar as posições (sa)*/
void	sort_three(t_list **stack)
{
	int	max;

	max = 0;
	max = max_node_v(*stack);
	if ((*stack)->value == max)
		ra(stack);
	if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_five_or_less(t_list **a, t_list **b)
{
	int	min;

	min = 0;
	if (stack_len(*a) == 3)
		sort_three(a);
	else
	{
		while (stack_len(*a) > 3)
		{
			min = min_node_v(*a);
			while (!is_on_top(*a, min))
				to_top_a(a, min);
			pb(a, b);
		}
		sort_three(a);
		while (stack_len(*b) != 0)
			pa(a, b);
	}
}
