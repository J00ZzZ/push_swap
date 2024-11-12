/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 04:04:02 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:36 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmin(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	ft_cmax(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

t_stack	*ft_min(t_stack *lst)
{
	int		min;
	t_stack	*tmp;

	min = lst->num;
	tmp = lst;
	while (lst)
	{
		if (lst->num < min)
		{
			min = lst->num;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

t_stack	*ft_max(t_stack *lst)
{
	int		max;
	t_stack	*tmp;

	max = lst->num;
	tmp = lst;
	while (lst)
	{
		if (lst->num > max)
		{
			max = lst->num;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	ft_issorted(t_stack *s)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*last;

	min = ft_min(s);
	max = ft_max(s);
	last = ft_stacklast(s);
	while (min != last)
	{
		if (min->next->num < min->num)
			return (0);
		min = min->next;
	}
	if (s == ft_min(s) && max == last)
		return (1);
	if ((last->num > s->num) || max->next != ft_min(s))
		return (0);
	while (s != max)
	{
		if (s->next->num < s->num)
			return (0);
		s = s->next;
	}
	return (1);
}
