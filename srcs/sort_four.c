/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:32:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 10:54:32 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_max(t_blist **base, t_blist **sub, t_list **actions, t_bool base_is_a)
{
	const int	min_i = ft_get_max_index(*base);

	if (min_i == 1)
		ft_rotate(base, actions, base_is_a);
	else if (min_i == 2)
	{
		ft_rotate(base, actions, base_is_a);
		ft_rotate(base, actions, base_is_a);
	}
	else if (min_i == 3)
		ft_rev_rotate(base, actions, base_is_a);
	ft_push(base, sub, actions, base_is_a);
}

void
	ft_sort_four(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	int	i;

	if (!base_is_a && ft_is_rev_sorted(*base))
	{
		i = -1;
		while (++i < 4)
			ft_push(base, sub, actions, base_is_a);
	}
	else
	{
		push_max(base, sub, actions, base_is_a);
		if (base_is_a)
		{
			ft_sort_three(base, sub, actions, base_is_a);
			ft_push(sub, base, actions, !base_is_a);
			ft_rotate(base, actions, base_is_a);
		}
		else
			ft_rev_sort_n_push_three(base, sub, actions, base_is_a);
	}
}
