/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_o_ro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:43:22 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:44 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		tmp->next = NULL;
		ft_stackadd_back(a, tmp);
	}
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int flag)
{
	t_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		tmp->next = NULL;
		ft_stackadd_back(b, tmp);
	}
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

void	ft_mintp(t_stack **a)
{
	t_stack	*min;
	int		len_a;

	len_a = ft_index_size(a);
	min = ft_min(*a);
	while (min->index2 > 0 && min->index2 <= len_a / 2)
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
