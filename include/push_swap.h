/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:52:32 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 23:46:06 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// need to delete
# include <stdio.h>

# define ERR_MSG "Error\n"

/* sort_stack.c */
void	ft_sort_stack(t_blist **stack_a, t_list **actions, const int
			size_of_stack);

/* sa.c */
void	ft_swap(t_blist **stack, t_list **actions, char c);

/* rotate.c */
void	ft_rotate(t_blist **stack, t_list **actions, char c);

/* rev_rotate.c */
void	ft_rev_rotate(t_blist **stack, t_list **actions, char c);

/* sort_two.c */
void	ft_sort_two(t_blist **stack, t_list **actions);

/* sort_three.c */
void	ft_sort_three(t_blist **stack, t_list **actions);

/* push.c */
void	ft_push(t_blist **from, t_blist **to, t_list **actions, char c);

/* sort_five.c */
void	ft_sort_five(t_blist **stack_a, t_list **actions);

/* sort_utils.c */
int		ft_get_max_index(t_blist *stack);
int		ft_get_min_index(t_blist *stack);

/* sort_four.c */
void	ft_sort_four(t_blist **stack_a, t_list **actions);

#endif
