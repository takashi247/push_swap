/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:52:32 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/09 09:13:43 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# include <stdio.h> // need to delete

# define ERR_MSG "Error\n"
# define MAX_SORTSIZE 5
# define MAX_MOVE 5
# define MIN_SEARCH 2
# define MIN_BLIST_SIZE 4

/* structure for push_swap */

typedef struct s_ps
{
	t_list	*actions;
	int		all_size;
	t_list	*p_sizes;
	int		sub_size;
	int		next_min;
	int		pivot;
	int		next_pivot;
	int		min_loc;
	int		next_min_loc;
	int		size_a;
	int		size_b;
	t_blist	**base;
}	t_ps;

/* sort_stack.c */
void	ft_sort_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a);

/* sa.c */
void	ft_swap(t_blist **stack, t_list **actions, t_bool is_a);

/* rotate.c */
void	ft_rotate(t_blist **stack, t_list **actions, t_bool is_a);

/* rev_rotate.c */
void	ft_rev_rotate(t_blist **stack, t_list **actions, t_bool is_a);

/* sort_two.c */
void	ft_sort_two(t_blist **a, t_blist **b, t_list **actions, t_bool is_a);

/* sort_three.c */
void	ft_sort_three(t_blist **a, t_blist **b, t_list **actions, t_bool is_a);
void	ft_rev_sort_n_push_three(t_blist **a, t_blist **b, t_list **actions,
			t_bool is_a);

/* push.c */
void	ft_push(t_blist **from, t_blist **to, t_list **actions, t_bool is_a);

/* sort_five.c */
void	ft_sort_five(t_blist **a, t_blist **b, t_list **actions,
			t_bool is_a);

/* sort_utils.c */
int		ft_get_max_index(t_blist *stack);
int		ft_get_min_index(t_blist *stack);
int		ft_get_max(t_blist *stack);
int		ft_get_min(t_blist *stack);
int		ft_get_index(t_blist *stack, int num);

/* sort_four.c */
void	ft_sort_four(t_blist **a, t_blist **b, t_list **actions, t_bool is_a);

/* convert_to_index.c */
void	ft_convert_to_index(t_blist *a, const int size_of_stack);

/* quick_sort.c */
void	ft_quick_sort(t_blist **a, t_blist **b, t_ps *ps);

/* action_utils.c */
void	ft_delete_action(t_list **actions);

/* push_swap.c */
void	ft_show_stack(t_blist *head, int size_of_stack);
void	ft_show_actions(t_list *actions);
t_bool	ft_is_valid_input(char **av, const int size_of_stack);

/* sort_utils_2.c */
t_bool	ft_is_rev_sorted(t_blist *stack);
int		ft_get_second_max(t_blist *stack, int max_i);

/* clear_a.c */
void	ft_clear_a(t_blist **a, t_ps *ps, int size);

/* clear_b.c */
void	ft_clear_b(t_blist **b, t_blist **a, t_ps *ps, int size);

/* initialize_b.c */
void	ft_initialize_b(t_blist **a, t_blist **b, t_ps *ps);

/* halve_stack.c */
void	ft_halve_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a);

/* search_next_min.c */
t_bool	ft_search_next_min(t_blist **b, t_blist **a, t_ps *ps);

/* rotate_n_keep.c */
void	ft_rotate_n_keep(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a);

/* reset_stack_position.c */
void	ft_reset_stack_position(t_blist **a, t_blist **b, t_ps *ps,
			t_bool is_a);

/* is_pushed_to_a.c */
t_bool	ft_is_pushed_to_a(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a);

#endif
