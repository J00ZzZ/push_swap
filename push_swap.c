/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:26:49 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:39:10 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int	i;

	i = ft_index_size(a);
	if (!ft_issorted(*a))
	{
		ft_smallsort(a, i);
		ft_bigsort(a, b, i);
	}
	ft_cleanlst(a, b);
	ft_mintp(a);
}

int	main(int ac, char **av)
{
	char	**stack;
	t_stack	*a;
	t_stack	*b;

	if (ac >= 2)
	{
		if (e_empty_inp(ac, av))
			return (write(2, "Error\n", 6));
		stack = stack_split(av);
		if (e_invld_inp(stack) || e_dup_inp(stack))
		{
			free_str(stack);
			return (write(2, "Error\n", 6));
		}
		a = NULL;
		b = NULL;
		stack_init(av, &a);
		ft_sort(&a, &b);
		free_str(stack);
		free_stk(&a);
	}
}
