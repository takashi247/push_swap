/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pushed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:58:34 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:26:04 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_double_pushable(t_blist *stack, t_ps *ps)
{
	int	first;
	int	second;

	if (!stack || !(stack->next))
		return (FALSE);
	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	if (first == ps->next_min + 1 && second == ps->next_min)
		return (TRUE);
	else
		return (FALSE);
}

static void
	double_push(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	ft_push(a, b, &(ps->actions), is_a);
	ft_push(a, b, &(ps->actions), is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ps->next_min += 2;
}

static t_bool
	is_close_to_tail(t_blist *a, t_ps *ps, t_bool is_a)
{
	int		base_len;
	int		current_min_loc;

	if (!is_a)
		return (TRUE);
	else
	{
		current_min_loc = ft_get_index(a, ps->next_min - 1);
		base_len = ft_blstsize(a);
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
}

t_bool
	ft_is_pushed_to_a(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	t_bool	is_pushed;

	is_pushed = FALSE;
	if (*(int *)(*a)->content == ps->next_min && is_close_to_tail(*a, ps, is_a))
		ft_rotate_n_keep(a, b, ps, is_a);
	else if (!is_a && is_double_pushable(*a, ps))
		double_push(a, b, ps, is_a);
	else if ((is_a && *(int *)(*a)->content <= ps->pivot))
		ft_push(a, b, &(ps->actions), is_a);
	else if (!is_a && ps->pivot < *(int *)(*a)->content)
	{
		ft_push(a, b, &(ps->actions), is_a);
		is_pushed = TRUE;
	}
	else
	{
		ft_rotate(a, &(ps->actions), is_a);
		if (is_a)
		{
			if (*b && *(int *)(*b)->content > ps->next_pivot)
				ft_rotate(b, &(ps->actions), !is_a);
			is_pushed = TRUE;
		}
	}
	return (is_pushed);
}
