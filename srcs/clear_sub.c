/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:44:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 14:30:38 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	move_min_to_tail(t_blist **base, t_ps *ps)
{
	int	i;
	int	len;

	i = ft_get_index(*base, ps->next_min - 1);
	len = ft_blstsize(*base);
	if (len / 2 <= i)
	{
		while (len - ++i)
			ft_rev_rotate(base, &(ps->actions), TRUE);
	}
	else
	{
		while (i + 1)
		{
			ft_rotate(base, &(ps->actions), TRUE);
			i--;
		}
	}
}

void
	ft_clear_sub(t_blist **sub, t_blist **base, t_ps *ps, int size)
{
	int	i;

	if (*(int *)(*base)->prev->content != ps->next_min - 1)
		move_min_to_tail(base, ps);
	i = 0;
	while (i < size)
	{
		ft_push(sub, base, &(ps->actions), FALSE);
		if (*(int *)(*base)->content == ps->next_min)
		{
			ft_rotate(base, &(ps->actions), TRUE);
			(ps->next_min)++;
		}
		else
			(*(int *)ps->batch_size_lst->content)++;
		i++;
	}
	*sub = NULL;
}
