/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edy.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:10:55 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 21:50:09 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_div(t_stack **a, t_stack **b, t_stack *tmp_a, int i)
{
	t_stack	*move;
	int		len_a;

	len_a = ft_index_size(a);
	move = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->rank == i && tmp_a->cost < move->cost)
			move = tmp_a;
		tmp_a = tmp_a->next;
	}
	if (move->index2 <= len_a / 2)
	{
		while (move->index2-- > 0)
			ra(a, 1);
	}
	else
	{
		while (move->index2++ < len_a)
			rra(a, 1);
	}
	pb(a, b);
}

void	ft_bigsort(t_stack **a, t_stack **b, int i)
{
	if (i >= 4 && i <= 100)
		ft_insertsort(a, b, 1);
	else if (i > 100 && i < 500)
		ft_insertsort(a, b, 2);
	else
		ft_insertsort(a, b, 5);
	if (ft_index_size(a) == 3)
		ft_solvethree(a);
}

void	ft_smallsort(t_stack **a, int i)
{
	if (i == 2 && (*a)->num > (*a)->next->num)
		ra(a, 1);
	else if (i == 3)
		ft_solvethree(a);
}

void	rot_min_to_top(t_stack **a)
{
	t_stack	*min;
	int		len_a;

	len_a = ft_index_size(a);
	min = ft_min(*a);
	while (min->index2 > 0 && min->index2 < len_a / 2)
	{
		ra(a, 1);
		min->index2--;
	}
	while (min->index2 > len_a / 2 && min->index2 < len_a)
	{
		rra(a, 1);
		min->index2++;
	}
}
