/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:39:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/25 19:31:15 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void
	push_three(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_push(a, b, actions, is_a);
		i++;
	}
}

void
	ft_rev_sort_n_push_three(t_blist **a, t_blist **b, t_list **actions,
		t_bool is_a)
{
	const int	top = *(int *)(*a)->content;
	const int	middle = *(int *)(*a)->next->content;
	const int	bottom = *(int *)(*a)->next->next->content;

	if (top < middle && middle < bottom)
	{
		ft_swap(a, actions, is_a);
		ft_rev_rotate(a, actions, is_a);
	}
	else if (middle > bottom && bottom > top)
		ft_rotate(a, actions, is_a);
	else if (bottom > top && top > middle)
		ft_rev_rotate(a, actions, is_a);
	else if (middle > top && top > bottom)
		ft_swap(a, actions, is_a);
	else if (top > bottom && bottom > middle)
	{
		ft_rev_rotate(a, actions, is_a);
		ft_swap(a, actions, is_a);
	}
	push_three(a, b, actions, is_a);
}

void
	ft_sort_three(t_blist **a, t_blist **b, t_list **actions, t_bool is_a)
{
	const int	top = *(int *)(*a)->content;
	const int	middle = *(int *)(*a)->next->content;
	const int	bottom = *(int *)(*a)->next->next->content;

	// if (!is_a && ft_is_rev_sorted(*a))
	// 	push_three(a, b, actions, is_a);
	if (!is_a)
		ft_rev_sort_n_push_three(a, b, actions, is_a);
	else
	{
		if (top > middle && bottom > top)
			ft_swap(a, actions, is_a);
		else if (top > middle && middle > bottom)
		{
			ft_swap(a, actions, is_a);
			ft_rev_rotate(a, actions, is_a);
		}
		else if (top > bottom && bottom > middle)
			ft_rotate(a, actions, is_a);
		else if (middle > bottom && bottom > top)
		{
			ft_swap(a, actions, is_a);
			ft_rotate(a, actions, is_a);
		}
		else if (middle > top && top > bottom)
			ft_rev_rotate(a, actions, is_a);
	}
}
