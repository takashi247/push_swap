/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_stack_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:29:41 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:30:22 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rotate_to_reset(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int	i;

	i = 0;
	while (i < ps->min_loc + 1)
	{
		ft_rotate(a, &(ps->actions), is_a);
		if (*b && ps->next_min_loc <= ps->size_b * 2 / 3
			&& *(int *)(*b)->content != ps->next_min)
			ft_rotate(b, &(ps->actions), !is_a);
		i++;
	}
}

static void
	rev_rotate_to_reset(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int	i;

	i = 0;
	while (i < ps->size_a - ps->min_loc - 1)
	{
		ft_rev_rotate(a, &(ps->actions), is_a);
		if (*b && ps->size_b / 2 < ps->next_min_loc
			&& *(int *)(*b)->content != ps->next_min)
			ft_rev_rotate(b, &(ps->actions), !is_a);
		i++;
	}
}

void
	ft_reset_stack_position(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	ps->min_loc = ft_get_index(*a, ps->next_min - 1);
	ps->next_min_loc = ft_get_index(*b, ps->next_min);
	ps->size_a = ft_blstsize(*a);
	ps->size_b = ft_blstsize(*b);
	if (ps->min_loc < ps->size_a * 2 / 3)
		rotate_to_reset(a, b, ps, is_a);
	else
		rev_rotate_to_reset(a, b, ps, is_a);
}
