/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:08:48 by lantonio          #+#    #+#             */
/*   Updated: 2024/07/17 09:32:01 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	wdqtd(char *str, char c)
{
	int	i;
	int	qtd;

	i = 0;
	qtd = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			qtd++;
			i++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (qtd);
}

int	ft_strlen2(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_getwd(char *str, char c, int start)
{
	int			i;
	char		*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ((ft_strlen2(str, c, start)) + 1));
	if (!s)
		return (NULL);
	while (str[start] != c && str[start])
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str, char c)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (wdqtd(str, c) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			split[j++] = ft_getwd(str, c, i++);
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	split[j] = NULL;
	return (split);
}

/*#include <stdio.h>
int main(void){
	char **split = ft_split("Ola meu nome e LouAntonio", ' ');
	int i = 0;
	while (split[i])
		printf("%s\n", split[i++]);
}*/