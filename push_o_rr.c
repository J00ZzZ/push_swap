/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_o_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:43:29 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:48 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = ft_stacklast(*a);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_stackadd_front(a, tmp);
	}
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = ft_stacklast(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_stackadd_front(b, tmp);
	}
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
