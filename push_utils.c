/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:30:10 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:39:14 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_size(t_stack **s)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		tmp->index2 = i;
		tmp->target = -1;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

long	ft_atol(char *str)
{
	long	neg;
	long	res;

	neg = 1;
	res = 0;
	while ((*str >= 0 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * neg);
}

char	**stack_split(char **av)
{
	char	*str;
	char	*str1;
	char	*str2;
	int		i;
	char	**new_stack;

	i = 0;
	str = ft_strdup("");
	while (av[i])
	{
		str1 = ft_strjoin(str, av[i]);
		free(str);
		str2 = ft_strjoin(str1, " ");
		str = ft_strdup(str2);
		free(str1);
		free(str2);
		i++;
	}
	new_stack = ft_split(str, ' ');
	free(str);
	return (new_stack);
}
