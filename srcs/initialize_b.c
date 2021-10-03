/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:54:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 11:31:54 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_next_min_in_head_or_tail(t_blist **b, t_blist **a, t_ps *ps)
{
	if (!a || !*a || !b || !*b)
		return (FALSE);
	if (*(int *)(*b)->prev->content == ps->next_min)
	{
		if (2 <= ft_blstsize(*b))
			ft_rev_rotate(b, &(ps->actions), FALSE);
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
	}
	else if (*(int *)(*b)->content == ps->next_min)
	{
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
	}
	else if (*(int *)(*b)->next->content == ps->next_min)
	{
		if (2 <= ft_blstsize(*b))
			ft_rotate(b, &(ps->actions), FALSE);
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
	}
	else
		return (FALSE);
	(ps->next_min)++;
	return (TRUE);
}

static void
	push_or_rotate(t_blist **a, t_blist **b, t_ps *ps)
{
	if (*(int *)(*a)->content == ps->next_min)
	{
		ft_rotate(a, &(ps->actions), TRUE);
		(ps->next_min)++;
	}
	else if (*(int *)(*a)->next->content == ps->next_min
		&& *(int *)(*a)->content == ps->next_min + 1)
	{
		ft_swap(a, &(ps->actions), TRUE);
		ft_rotate(a, &(ps->actions), TRUE);
		(ps->next_min)++;
	}
	else
		ft_push(a, b, &(ps->actions), TRUE);
}

void
	ft_initialize_b(t_blist **a, t_blist **b, t_ps *ps)
{
	int		i;
	t_list	*tmp;

	if (!ps->p_sizes)
		ft_halve_stack(a, b, ps, TRUE);
	else
	{
		i = 0;
		while (i < *(int *)ps->p_sizes->content)
		{
			if (is_next_min_in_head_or_tail(b, a, ps))
				continue ;
			push_or_rotate(a, b, ps);
			i++;
		}
		tmp = ps->p_sizes;
		ps->p_sizes = ps->p_sizes->next;
		ft_lstdelone(tmp, free);
	}
}
