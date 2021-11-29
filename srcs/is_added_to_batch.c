/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_added_to_batch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:58:34 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 15:53:05 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_double_pushable(t_blist *stack, t_ps *ps)
{
	int	first;
	int	second;

	if (!stack || !(stack->next) || !ps)
		return (FALSE);
	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	if (first == ps->next_min + 1 && second == ps->next_min)
		return (TRUE);
	else
		return (FALSE);
}

static void
	double_push(t_blist **base, t_blist **sub, t_ps *ps)
{
	ft_push(base, sub, &(ps->actions), FALSE);
	ft_push(base, sub, &(ps->actions), FALSE);
	ft_rotate(sub, &(ps->actions), TRUE);
	ft_rotate(sub, &(ps->actions), TRUE);
	ps->next_min += 2;
}

static t_bool
	is_close_to_tail(t_blist *base, t_ps *ps)
{
	int		base_len;
	int		current_min_loc;

	current_min_loc = ft_get_index(base, ps->next_min - 1);
	base_len = ft_blstsize(base);
	if (current_min_loc == 0)
		return (TRUE);
	if ((base_len / 2 <= current_min_loc)
		&& (MAX_MOVE < base_len - current_min_loc))
		return (FALSE);
	else if ((current_min_loc < base_len / 2)
		&& (MAX_MOVE < current_min_loc))
		return (FALSE);
	return (TRUE);
}

t_bool
	handle_base_b_case(t_blist **base, t_blist **sub, t_ps *ps)
{
	t_bool	is_added;

	is_added = FALSE;
	if (*(int *)(*base)->content == ps->next_min)
	{
		ft_push(base, sub, &(ps->actions), FALSE);
		ft_rotate(sub, &(ps->actions), TRUE);
		(ps->next_min)++;
	}
	else if (is_double_pushable(*base, ps))
		double_push(base, sub, ps);
	else if (ps->pivot < *(int *)(*base)->content)
	{
		ft_push(base, sub, &(ps->actions), FALSE);
		is_added = TRUE;
	}
	else
		ft_rotate(base, &(ps->actions), FALSE);
	return (is_added);
}

t_bool
	ft_is_added_to_batch(t_blist **base, t_blist **sub, t_ps *ps,
		t_bool base_is_a)
{
	t_bool	is_added;

	is_added = FALSE;
	if (base_is_a)
	{
		if (*(int *)(*base)->content == ps->next_min
			&& is_close_to_tail(*base, ps))
			ft_rotate_n_keep(base, sub, ps);
		else if (*(int *)(*base)->content <= ps->pivot)
			ft_push(base, sub, &(ps->actions), base_is_a);
		else
		{
			ft_rotate(base, &(ps->actions), base_is_a);
			if (*sub && *(int *)(*sub)->content > ps->next_pivot)
				ft_rotate(sub, &(ps->actions), !base_is_a);
			is_added = TRUE;
		}
	}
	else
		is_added = handle_base_b_case(base, sub, ps);
	return (is_added);
}
