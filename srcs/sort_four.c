/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:32:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 20:39:36 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_min(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	min_i = ft_get_min_index(*a);

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
	push_min(a, b, actions, is_a);
	ft_sort_three(a, actions, is_a);
	ft_push(b, a, actions, !is_a);
}
