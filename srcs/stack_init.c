/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:55:07 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/25 16:17:43 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(const char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '-' || *str == 32)
			str++;
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/*Converte uma string para long*/
static long	ft_atol(char *str)
{
	long	num;
	int		signal;
	int		i;

	num = 0;
	signal = 1;
	i = 0;
	while (str[i] && (str[i] <= 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signal *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * signal);
}

/*Busca erros de sintaxe,
extrapolações dos limites do inteiro,
e duplicações dos números
se ouver algum deles, a stack e a matriz são liberadas,e o programa encerrado
caso contrário, o número é adicionado à stack
*/
void	init_a(t_list **stack_a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!is_number(av[i]))
			error_free(stack_a, av);
		if (sintax_error(av[i]))
			error_free(stack_a, av);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(stack_a, av);
		if (is_duplicated(*stack_a, (int)n))
			error_free(stack_a, av);
		add_node(stack_a, (int)n);
		i++;
	}
	free_matrix(av);
}

/*Adiciona nós ao final da stack a após a verificação de erros*/
void	add_node(t_list **stack, int n)
{
	t_list	*node;
	t_list	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
	}
	else
	{
		last = last_node(*stack);
		last->next = node;
	}
}
