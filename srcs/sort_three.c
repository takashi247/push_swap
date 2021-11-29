/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:39:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 10:16:32 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_three(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_push(base, sub, actions, base_is_a);
		i++;
	}
}

void
	ft_rev_sort_n_push_three(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	const int	top = *(int *)(*base)->content;
	const int	middle = *(int *)(*base)->next->content;
	const int	bottom = *(int *)(*base)->next->next->content;

	if (top > bottom && bottom > middle)
	{
		ft_push(base, sub, actions, base_is_a);
		ft_swap(base, actions, base_is_a);
		ft_push(base, sub, actions, base_is_a);
		ft_push(base, sub, actions, base_is_a);
		return ;
	}
	else if (top < middle && middle < bottom)
	{
		ft_swap(base, actions, base_is_a);
		ft_rev_rotate(base, actions, base_is_a);
	}
	else if (middle > bottom && bottom > top)
		ft_rotate(base, actions, base_is_a);
	else if (bottom > top && top > middle)
		ft_rev_rotate(base, actions, base_is_a);
	else if (middle > top && top > bottom)
		ft_swap(base, actions, base_is_a);
	push_three(base, sub, actions, base_is_a);
}

void
	ft_sort_three(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	const int	top = *(int *)(*base)->content;
	const int	middle = *(int *)(*base)->next->content;
	const int	bottom = *(int *)(*base)->next->next->content;

	if (!base_is_a)
		ft_rev_sort_n_push_three(base, sub, actions, base_is_a);
	else
	{
		if (top > middle && bottom > top)
			ft_swap(base, actions, base_is_a);
		else if (top > middle && middle > bottom)
		{
			ft_swap(base, actions, base_is_a);
			ft_rev_rotate(base, actions, base_is_a);
		}
		else if (top > bottom && bottom > middle)
			ft_rotate(base, actions, base_is_a);
		else if (middle > bottom && bottom > top)
		{
			ft_swap(base, actions, base_is_a);
			ft_rotate(base, actions, base_is_a);
		}
		else if (middle > top && top > bottom)
			ft_rev_rotate(base, actions, base_is_a);
	}
}
