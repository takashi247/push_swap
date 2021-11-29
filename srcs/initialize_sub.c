/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:54:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 14:30:51 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_next_min_in_head_or_tail(t_blist **sub, t_blist **base, t_ps *ps)
{
	if (!base || !*base || !sub || !*sub)
		return (FALSE);
	if (*(int *)(*sub)->prev->content == ps->next_min)
	{
		if (2 <= ft_blstsize(*sub))
			ft_rev_rotate(sub, &(ps->actions), FALSE);
		ft_push(sub, base, &(ps->actions), FALSE);
		ft_rotate(base, &(ps->actions), TRUE);
	}
	else if (*(int *)(*sub)->content == ps->next_min)
	{
		ft_push(sub, base, &(ps->actions), FALSE);
		ft_rotate(base, &(ps->actions), TRUE);
	}
	else if (*(int *)(*sub)->next->content == ps->next_min)
	{
		if (2 <= ft_blstsize(*sub))
			ft_rotate(sub, &(ps->actions), FALSE);
		ft_push(sub, base, &(ps->actions), FALSE);
		ft_rotate(base, &(ps->actions), TRUE);
	}
	else
		return (FALSE);
	(ps->next_min)++;
	return (TRUE);
}

static void
	push_or_rotate(t_blist **base, t_blist **sub, t_ps *ps)
{
	if (*(int *)(*base)->content == ps->next_min)
	{
		ft_rotate(base, &(ps->actions), TRUE);
		(ps->next_min)++;
	}
	else if (*(int *)(*base)->next->content == ps->next_min
		&& *(int *)(*base)->content == ps->next_min + 1)
	{
		ft_swap(base, &(ps->actions), TRUE);
		ft_rotate(base, &(ps->actions), TRUE);
		(ps->next_min)++;
	}
	else
		ft_push(base, sub, &(ps->actions), TRUE);
}

void
	ft_initialize_sub(t_blist **base, t_blist **sub, t_ps *ps)
{
	int		i;
	t_list	*tmp;

	if (!ps->batch_size_lst)
		ft_halve_stack(base, sub, ps, TRUE);
	else
	{
		i = 0;
		while (i < *(int *)ps->batch_size_lst->content)
		{
			if (is_next_min_in_head_or_tail(sub, base, ps))
				continue ;
			push_or_rotate(base, sub, ps);
			i++;
		}
		tmp = ps->batch_size_lst;
		ps->batch_size_lst = ps->batch_size_lst->next;
		ft_lstdelone(tmp, free);
	}
}
