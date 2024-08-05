/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:58:24 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/25 12:27:38 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Libera todos os nós de uma stack e a define como NULL*/
void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = NULL;
}

/*libera a matriz que recebe os paŕametros vindos da main*/
void	free_matrix(char **av)
{
	int	i;

	i = 0;
	if (*av == NULL || av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

/*Invoca a função de liberação da stack 
e imprime a mensagem de erro*/
void	error_free(t_list **stack_a, char **av)
{
	free_matrix(av);
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

/*Verifica se o parámetro passado é um número válido*/
int	sintax_error(char *str_nbr)
{
	if (!(ft_issign(*str_nbr) || ft_isdigit(*str_nbr)))
		return (1);
	if (ft_issign(str_nbr[1]) && !ft_isdigit(str_nbr[1]))
		return (1);
	while (*++str_nbr)
		if (!ft_isdigit(*str_nbr))
			return (1);
	return (0);
}

/*Verifica se o número atual já existe na stack*/
int	is_duplicated(t_list *stack, int n)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
