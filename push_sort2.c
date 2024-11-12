/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 05:34:12 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:38:59 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_moves(t_stack **b, int len_a, int len_b)
{
	t_stack	*tmp_b;
	t_stack	*move;
	int		move_a;
	int		move_b;

	tmp_b = *b;
	while (tmp_b)
	{
		move_a = ft_cmin(tmp_b->target, len_a - tmp_b->target);
		move_b = ft_cmin(tmp_b->index2, len_b - tmp_b->index2);
		tmp_b->cost = ft_cmax(move_a, move_b);
		if ((move_a > len_a / 2 && move_b < len_b / 2) || (move_a < len_a / 2
				&& move_b > len_b / 2))
			tmp_b->cost = move_a + move_b;
		tmp_b = tmp_b->next;
	}
	tmp_b = *b;
	move = tmp_b;
	while (tmp_b->next)
	{
		if (tmp_b->next->cost < move->cost)
			move = tmp_b->next;
		tmp_b = tmp_b->next;
	}
	return (move);
}

void	rot_rrb_dir(t_stack **a, t_stack **b, t_stack *clean)
{
	int	len_a;
	int	len_b;

	len_b = ft_index_size(b);
	len_a = ft_b_target(a, b);
	if (clean->index2 > len_b / 2 && clean->target <= len_a / 2)
	{
		while (clean->index2++ < len_b)
			rrb(b, 1);
		while (clean->target-- > 0)
			ra(a, 1);
	}
	else if (clean->index2 > len_b / 2 && clean->target > len_a / 2)
	{
		while (clean->index2 < len_b && clean->target < len_a)
		{
			rrr(a, b);
			clean->index2++;
			clean->target++;
		}
		while (clean->index2++ < len_b)
			rrb(b, 1);
		while (clean->target++ < len_a)
			rra(a, 1);
	}
}

void	rot_rb_dir(t_stack **a, t_stack **b, t_stack *clean)
{
	int	len_a;
	int	len_b;

	len_b = ft_index_size(b);
	len_a = ft_b_target(a, b);
	if (clean->index2 <= len_b / 2 && clean->target > len_a / 2)
	{
		while (clean->index2-- > 0)
			rb(b, 1);
		while (clean->target++ < len_a)
			rra(a, 1);
	}
	else if (clean->index2 <= len_b / 2 && clean->target <= len_a / 2)
	{
		while (clean->index2 > 0 && clean->target > 0)
		{
			rr(a, b);
			clean->index2--;
			clean->target--;
		}
		while (clean->index2-- > 0)
			rb(b, 1);
		while (clean->target-- > 0)
			ra(a, 1);
	}
}

int	ft_b_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len_a;

	tmp_b = *b;
	while (tmp_b)
	{
		len_a = ft_index_size(a);
		tmp_a = *a;
		while (tmp_a)
		{
			if (!tmp_a->prev && tmp_b->num < tmp_a->num
				&& tmp_b->num > ft_stacklast(*a)->num)
				tmp_b->target = tmp_a->index2;
			if (tmp_a->prev && tmp_b->num < tmp_a->num
				&& tmp_b->num > tmp_a->prev->num)
				tmp_b->target = tmp_a->index2;
			tmp_a = tmp_a->next;
		}
		if (tmp_b->target == -1 && (tmp_b->num > ft_max(*a)->num
				|| tmp_b->num < ft_min(*a)->num))
			tmp_b->target = ft_min(*a)->index2;
		tmp_b = tmp_b->next;
	}
	return (len_a);
}

void	ft_cleanlst(t_stack **a, t_stack **b)
{
	t_stack	*move;
	int		len_a;
	int		len_b;

	while (ft_index_size(b))
	{
		len_b = ft_index_size(b);
		len_a = ft_b_target(a, b);
		move = ft_moves(b, len_a, len_b);
		if ((move->index2 > len_b / 2 && move->target <= len_a / 2)
			|| (move->index2 > len_b / 2 && move->target > len_a / 2))
			rot_rrb_dir(a, b, move);
		else
			rot_rb_dir(a, b, move);
		pa(a, b);
	}
}
