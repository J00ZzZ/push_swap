/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stk2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:30:42 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:39:07 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_nth_stack(t_stack *s, int n)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = s;
	while (i < n && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
