/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_free_n_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:49:31 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:40 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	e_dup_inp(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	e_invld_inp(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (j != 0 || av[i][j + 1] == 0)
					return (1);
			}
			else
			{
				if (!ft_isdigit(av[i][j]))
					return (1);
			}
		}
		if (!j || ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
			return (1);
	}
	return (0);
}

int	e_empty_inp(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '\0')
			return (1);
		if (ac > 2)
		{
			while (av[i][j])
			{
				if ((av[i][j] == '-' || av[i][j] == '+') && (j != 0 || av[i][j
						+ 1] == 0))
					return (0);
				if (!(av[i][j] == '-' || av[i][j] == '+')
					&& (!ft_isdigit(av[i][j])))
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	free_stk(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	free_str(char **new_av)
{
	int	i;

	i = -1;
	while (new_av[++i])
		free(new_av[i]);
	free(new_av);
}
