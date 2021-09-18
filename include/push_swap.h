/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:52:32 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 01:47:50 by tnishina         ###   ########.fr       */
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
void	ft_sort_stack(t_blist **stack_a, t_list **actions, const int size_of_stack);

/* sa.c */
void	ft_swap(t_blist **stack, t_list **actions, char *action);

/* rotate.c */
void	ft_rotate(t_blist **stack, t_list **actions, char *action);

/* rev_rotate.c */
void	ft_rev_rotate(t_blist **stack, t_list **actions, char *action);

#endif
