/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_stack_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:29:41 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/29 22:56:18 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rotate_to_reset(t_blist **base, t_blist **sub, t_ps *ps, t_bool base_is_a)
{
	int	i;

	i = 0;
	while (i < ps->min_loc + 1)
	{
		ft_rotate(base, &(ps->actions), base_is_a);
		if (*sub && ps->next_min_loc <= ps->size_sub / 2
			&& *(int *)(*sub)->content != ps->next_min)
			ft_rotate(sub, &(ps->actions), !base_is_a);
		i++;
	}
}

static void
	rev_rotate_to_reset(t_blist **base, t_blist **sub, t_ps *ps,
		t_bool base_is_a)
{
	int	i;

	i = 0;
	while (i < ps->size_base - ps->min_loc - 1)
	{
		ft_rev_rotate(base, &(ps->actions), base_is_a);
		if (*sub && ps->size_sub / 2 < ps->next_min_loc
			&& *(int *)(*sub)->content != ps->next_min)
			ft_rev_rotate(sub, &(ps->actions), !base_is_a);
		i++;
	}
}

void
	ft_reset_stack_position(t_blist **base, t_blist **sub, t_ps *ps,
		t_bool base_is_a)
{
	ps->min_loc = ft_get_index(*base, ps->next_min - 1);
	ps->next_min_loc = ft_get_index(*sub, ps->next_min);
	ps->size_base = ft_blstsize(*base);
	ps->size_sub = ft_blstsize(*sub);
	if (ps->min_loc < ps->size_base / 2)
		rotate_to_reset(base, sub, ps, base_is_a);
	else
		rev_rotate_to_reset(base, sub, ps, base_is_a);
}
