/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:44:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/02 16:52:22 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	move_min_to_tail(t_blist **a, t_ps *ps)
{
	int	i;
	int	len;

	i = ft_get_index(*a, ps->next_min - 1);
	len = ft_blstsize(*a);
	if (len / 2 <= i)
	{
		while (len - ++i)
			ft_rev_rotate(a, &(ps->actions), TRUE);
	}
	else
	{
		while (i + 1)
		{
			ft_rotate(a, &(ps->actions), TRUE);
			i--;
		}
	}
}

void
	ft_clear_b(t_blist **b, t_blist **a, t_ps *ps, int size)
{
	int	i;

	if (*(int *)(*a)->prev->content != ps->next_min - 1)
		move_min_to_tail(a, ps);
	i = 0;
	while (i < size)
	{
		ft_push(b, a, &(ps->actions), FALSE);
		if (*(int *)(*a)->content == ps->next_min)
		{
			ft_rotate(a, &(ps->actions), TRUE);
			(ps->next_min)++;
		}
		else
			(*(int *)ps->p_sizes->content)++;
		i++;
	}
	*b = NULL;
}
