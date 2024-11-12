/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:43:51 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:55 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_rank(int *array, t_stack *a, int j)
{
	int	i;
	int	k;
	int	tmp;

	i = -1;
	while (++i < j)
	{
		array[i] = a->num;
		a = a->next;
	}
	i = -1;
	while (++i < j)
	{
		k = i;
		while (++k < j)
		{
			if (array[i] > array[k])
			{
				tmp = array[i];
				array[i] = array[k];
				array[k] = tmp;
			}
		}
	}
	return (array);
}

void	ft_rank(t_stack **a, int div, int size)
{
	int		*array;
	int		i;
	int		group;
	t_stack	*tmp_a;

	tmp_a = *a;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return ;
	group = size / div;
	if (group * div != ft_index_size(a))
		group++;
	array = ft_sort_rank(array, *a, size);
	while (tmp_a)
	{
		i = -1;
		while (++i < size)
		{
			if (tmp_a->num == array[i])
				break ;
		}
		tmp_a->rank = i / group;
		tmp_a = tmp_a->next;
	}
	free(array);
}

void	ft_insertsort(t_stack **a, t_stack **b, int div)
{
	int		i;
	int		len_a;
	t_stack	*tmp_a;

	ft_rank(a, div, ft_index_size(a));
	i = 0;
	while (ft_index_size(a) > 3 && !ft_issorted(*a))
	{
		len_a = ft_index_size(a);
		tmp_a = *a;
		while (tmp_a)
		{
			tmp_a->cost = ft_cmin(tmp_a->index2, len_a - tmp_a->index2);
			tmp_a = tmp_a->next;
		}
		tmp_a = *a;
		while (tmp_a->rank != i && tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_a->rank != i)
			tmp_a = NULL;
		if (!tmp_a)
			i++;
		else
			ft_div(a, b, tmp_a, i);
	}
}

void	ft_solvethree(t_stack **s)
{
	int	first;
	int	second;
	int	third;

	first = (*s)->num;
	second = (*s)->next->num;
	third = (*s)->next->next->num;
	if (first < third && second > third)
	{
		ra(s, 1);
		sa(s, 1);
		rra(s, 1);
	}
	else if (first < third && first > second)
		sa(s, 1);
	else if (first < second && first > third)
		rra(s, 1);
	else if (first > third && second < third)
		ra(s, 1);
	else if (first > second && second > third)
	{
		sa(s, 1);
		rra(s, 1);
	}
}

void	ft_solvefnf(t_stack **a, t_stack **b)
{
	while (ft_index_size(b) <= 1)
	{
		if ((*a)->index == 0 || (*a)->next->index == 1)
			pb(a, b);
		else
			ra(a, 1);
	}
	if ((*b)->index == 0)
		sb(b, 1);
	if ((get_nth_stack(*a, 2)->index) != 4)
	{
		if ((*a)->index == 4)
			ra(a, 1);
		else
			rra(a, 1);
	}
	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
	pa(a, b);
	pa(a, b);
}
