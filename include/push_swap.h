/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:52:32 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 18:09:50 by tnishina         ###   ########.fr       */
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

/* structure for push_swap */

typedef struct s_ps
{
	t_list	*actions;
	int		all_size;
	t_list	*p_sizes;
	int		n_sorted;
	int		sub_size;
}	t_ps;

/* sort_stack.c */
void	ft_sort_stack(t_blist **a, t_blist **b, t_ps *ps, char c);

/* sa.c */
void	ft_swap(t_blist **stack, t_list **actions, char c);

/* rotate.c */
void	ft_rotate(t_blist **stack, t_list **actions, char c);

/* rev_rotate.c */
void	ft_rev_rotate(t_blist **stack, t_list **actions, char c);

/* sort_two.c */
void	ft_sort_two(t_blist **stack, t_list **actions, char c);

/* sort_three.c */
void	ft_sort_three(t_blist **stack, t_list **actions, char c);

/* push.c */
void	ft_push(t_blist **from, t_blist **to, t_list **actions, char c);

/* sort_five.c */
void	ft_sort_five(t_blist **a, t_blist **b, t_list **actions, char c);

/* sort_utils.c */
int		ft_get_max_index(t_blist *stack);
int		ft_get_min_index(t_blist *stack);
int		ft_get_max(t_blist *stack);
int		ft_get_min(t_blist *stack);

/* sort_four.c */
void	ft_sort_four(t_blist **a, t_blist **b, t_list **actions, char c);

/* convert_to_index.c */
void	ft_convert_to_index(t_blist *a, const int size_of_stack);

/* quick_sort.c */
void	ft_quick_sort(t_blist **a, t_blist **b, t_ps *ps);

#endif
