/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:37:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/25 15:40:23 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_two(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	top = *(int *)(*a)->content;
	const int	bottom = *(int *)(*a)->next->content;
	int			i;

	if (!is_a && ft_is_rev_sorted(*a))
	{
		i = -1;
		while (++i < 2)
			ft_push(a, b, actions, is_a);
	}
	else if (top > bottom)
		ft_swap(a, actions, is_a);
}
