/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:32:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/25 17:13:38 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_max(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	min_i = ft_get_max_index(*a);

	if (min_i == 1)
		ft_rotate(a, actions, is_a);
	else if (min_i == 2)
	{
		ft_rotate(a, actions, is_a);
		ft_rotate(a, actions, is_a);
	}
	else if (min_i == 3)
		ft_rev_rotate(a, actions, is_a);
	ft_push(a, b, actions, is_a);
}

void
	ft_sort_four(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	int	i;

	if (!is_a && ft_is_rev_sorted(*a))
	{
		i = -1;
		while (++i < 4)
			ft_push(a, b, actions, is_a);
	}
	else
	{
		push_max(a, b, actions, is_a);
		if (is_a)
		{
			ft_sort_three(a, b, actions, is_a);
			ft_push(b, a, actions, !is_a);
			ft_rotate(a, actions, is_a);
		}
		else
			ft_rev_sort_n_push_three(a, b, actions, is_a);
	}
}
