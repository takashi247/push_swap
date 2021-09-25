/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:40:57 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/25 19:12:19 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_n_rotate(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	max = ft_get_max(*a);
	const int	max_i = ft_get_index(*a, max);
	const int	next_max_i = ft_get_index(*a, max - 1);

	ft_push(a, b, actions, is_a);
	if (max_i == 2 || next_max_i == 2)
		ft_rotate(a, actions, is_a);
	else if (max_i == 3 || next_max_i == 3)
	{
		ft_rotate(a, actions, is_a);
		ft_rotate(a, actions, is_a);
	}
	else if (max_i == 4 || next_max_i == 4)
		ft_rev_rotate(a, actions, is_a);
	ft_push(a, b, actions, is_a);
	if (next_max_i == 0)
		ft_swap(b, actions, !is_a);
}

static void
	rotate_n_push(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	max = ft_get_max(*a);
	const int	max_i = ft_get_index(*a, max);
	const int	next_max_i = ft_get_index(*a, max - 1);

	if (max_i == 4 || next_max_i == 4)
		ft_rev_rotate(a, actions, is_a);
	else
		ft_rotate(a, actions, is_a);
	if (max_i == 1 || next_max_i == 1)
		ft_push(a, b, actions, is_a);
	if ((max_i == 1 && next_max_i == 3) || (max_i == 3 && next_max_i == 1)
		|| (max_i == 1 && next_max_i == 4) || (max_i == 4 && next_max_i == 1)
		|| (max_i == 2 && next_max_i == 3) || (max_i == 3 && next_max_i == 2))
		ft_rotate(a, actions, is_a);
	if ((max_i == 2 && next_max_i == 3) || (max_i == 3 && next_max_i == 2)
		|| (max_i == 2 && next_max_i == 4) || (max_i == 4 && next_max_i == 2)
		|| (max_i == 3 && next_max_i == 4) || (max_i == 4 && next_max_i == 3))
		ft_push(a, b, actions, is_a);
	if ((max_i == 2 && next_max_i == 4) || (max_i == 4 && next_max_i == 2))
	{
		ft_rotate(a, actions, is_a);
		ft_rotate(a, actions, is_a);
	}
	else if ((max_i == 3 && next_max_i == 4) || (max_i == 4 && next_max_i == 3))
		ft_rev_rotate(a, actions, is_a);
	ft_push(a, b, actions, is_a);
	if (*(int *)(*b)->content > *(int *)(*b)->next->content)
		ft_swap(b, actions, !is_a);
}

static void
	push_maxs(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	max = ft_get_max(*a);
	const int	max_i = ft_get_index(*a, max);
	const int	next_max_i = ft_get_index(*a, max - 1);

	if (max_i == 0 || next_max_i == 0)
		push_n_rotate(a, b, actions, is_a);
	else
		rotate_n_push(a, b, actions, is_a);
}

void
	ft_sort_five(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	int		i;

	if (!is_a && ft_is_rev_sorted(*a))
	{
		i = -1;
		while (++i < 5)
			ft_push(a, b, actions, is_a);
	}
	else
	{
		push_maxs(a, b, actions, is_a);
		if (is_a)
		{
			ft_sort_three(a, b, actions, is_a);
			ft_push(b, a, actions, !is_a);
			ft_rotate(a, actions, is_a);
			ft_push(b, a, actions, !is_a);
			ft_rotate(a, actions, is_a);
		}
		else
			ft_rev_sort_n_push_three(a, b, actions, is_a);
	}
}
