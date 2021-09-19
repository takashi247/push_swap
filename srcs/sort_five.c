/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:40:57 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 20:41:15 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_n_rotate(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	max_i = ft_get_max_index(*a);
	const int	min_i = ft_get_min_index(*a);

	ft_push(a, b, actions, is_a);
	if (max_i == 2 || min_i == 2)
		ft_rotate(a, actions, is_a);
	else if (max_i == 3 || min_i == 3)
	{
		ft_rotate(a, actions, is_a);
		ft_rotate(a, actions, is_a);
	}
	else if (max_i == 4 || min_i == 4)
		ft_rev_rotate(a, actions, is_a);
	ft_push(a, b, actions, is_a);
}

static void
	rotate_n_push(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	max_i = ft_get_max_index(*a);
	const int	min_i = ft_get_min_index(*a);

	if (max_i == 4 || min_i == 4)
		ft_rev_rotate(a, actions, is_a);
	else
		ft_rotate(a, actions, is_a);
	if (max_i == 1 || min_i == 1)
		ft_push(a, b, actions, is_a);
	if ((max_i == 1 && min_i == 3) || (max_i == 3 && min_i == 1)
		|| (max_i == 1 && min_i == 4) || (max_i == 4 && min_i == 1)
		|| (max_i == 2 && min_i == 3) || (max_i == 3 && min_i == 2))
		ft_rotate(a, actions, is_a);
	if ((max_i == 2 && min_i == 3) || (max_i == 3 && min_i == 2)
		|| (max_i == 2 && min_i == 4) || (max_i == 4 && min_i == 2)
		|| (max_i == 3 && min_i == 4) || (max_i == 4 && min_i == 3))
		ft_push(a, b, actions, is_a);
	if ((max_i == 2 && min_i == 4) || (max_i == 4 && min_i == 2))
	{
		ft_rotate(a, actions, is_a);
		ft_rotate(a, actions, is_a);
	}
	else if ((max_i == 3 && min_i == 4) || (max_i == 4 && min_i == 3))
		ft_rev_rotate(a, actions, is_a);
	ft_push(a, b, actions, is_a);
}

static void
	push_max_min(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	max_i = ft_get_max_index(*a);
	const int	min_i = ft_get_min_index(*a);

	if (max_i == 0 || min_i == 0)
		push_n_rotate(a, b, actions, is_a);
	else
		rotate_n_push(a, b, actions, is_a);
}

void
	ft_sort_five(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	int		top;
	int		bottom;

	push_max_min(a, b, actions, is_a);
	ft_sort_three(a, actions, is_a);
	top = *(int *)(*b)->content;
	bottom = *(int *)(*b)->next->content;
	if (top > bottom)
	{
		ft_push(b, a, actions, !is_a);
		ft_rotate(a, actions, is_a);
		ft_push(b, a, actions, !is_a);
	}
	else
	{
		ft_push(b, a, actions, !is_a);
		ft_push(b, a, actions, !is_a);
		ft_rotate(a, actions, is_a);
	}
}
