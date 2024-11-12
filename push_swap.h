/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:26:58 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/12 02:39:39 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				index2;
	int				target;
	int				cost;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* Algo 5 */
void				ft_div(t_stack **a, t_stack **b, t_stack *tmp_a, int i);
void				ft_fillpos(t_stack *a);
void				ft_bigsort(t_stack **a, t_stack **b, int i);
void				ft_smallsort(t_stack **a, int i);
void				ft_sort(t_stack **a, t_stack **b);

/* Free and Error 5 */
int					e_dup_inp(char **av);
int					e_invld_inp(char **av);
int					e_empty_inp(int ac, char **av);
void				free_stk(t_stack **a);
void				free_str(char **new_av);

/* Operator RO 3 */
void				ra(t_stack **a, int flag);
void				rb(t_stack **b, int flag);
void				rr(t_stack **a, t_stack **b);
void				ft_mintp(t_stack **a);

/* Operator RR 3 */
void				rra(t_stack **a, int flag);
void				rrb(t_stack **b, int flag);
void				rrr(t_stack **a, t_stack **b);

/* Operator SP 5 */
void				sa(t_stack **a, int flag);
void				sb(t_stack **b, int flag);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

/* Sort 10 */
int					*ft_sort_rank(int *array, t_stack *a, int j);
void				ft_rank(t_stack **a, int div, int size);
void				ft_insertsort(t_stack **a, t_stack **b, int div);
void				ft_solvethree(t_stack **s);
void				ft_solvefnf(t_stack **a, t_stack **b);
void				ft_cleanlst(t_stack **a, t_stack **b);
int					ft_b_target(t_stack **a, t_stack **b);
void				rot_rrb_dir(t_stack **a, t_stack **b, t_stack *clean);
void				rot_rb_dir(t_stack **a, t_stack **b, t_stack *clean);
t_stack				*ft_moves(t_stack **b, int len_a, int len_b);

/* Stacks 6 */
t_stack				*ft_stacknew(int content);
t_stack				*ft_stacklast(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
void				stack_init(char **av, t_stack **a);
t_stack				*get_nth_stack(t_stack *s, int n);

/* Utils 6 */
int					ft_index_size(t_stack **s);
long				ft_atol(char *str);
char				**stack_split(char **av);
int					ft_issorted(t_stack *s);
t_stack				*ft_min(t_stack *lst);
t_stack				*ft_max(t_stack *lst);
int					ft_cmin(int x, int y);
int					ft_cmax(int x, int y);

#endif
