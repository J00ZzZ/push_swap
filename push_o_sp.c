/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_o_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:43:15 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:51 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = tmp;
	}
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = tmp;
	}
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = NULL;
		if (!*a)
			*a = tmp;
		else
			ft_stackadd_front(a, tmp);
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		tmp->next = NULL;
		if (!*b)
			*b = tmp;
		else
			ft_stackadd_front(b, tmp);
	}
	ft_printf("pb\n");
}
