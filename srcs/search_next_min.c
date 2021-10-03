/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_next_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:38:05 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 11:53:39 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	reset_position(t_blist **a, t_blist **b, t_ps *ps, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (*(int *)(*b)->content == ps->next_min)
		{
			ft_push(b, a, &(ps->actions), FALSE);
			ft_rotate(a, &(ps->actions), TRUE);
			(ps->next_min)++;
			i--;
		}
		else
		{
			ft_rotate(b, &(ps->actions), FALSE);
			j++;
		}
	}
}

t_bool
	ft_search_next_min(t_blist **b, t_blist **a, t_ps *ps)
{
	int		i;
	int		j;
	t_blist	*prev;

	if (!b || !(*b) || ft_blstsize(*b) < MIN_BLIST_SIZE)
		return (FALSE);
	i = 0;
	prev = (*b)->prev;
	while (prev && i < MIN_SEARCH)
	{
		if (*(int *)prev->content == ps->next_min)
		{
			j = -1;
			while (++j < i + 1)
				ft_rev_rotate(b, &(ps->actions), FALSE);
			ft_push(b, a, &(ps->actions), FALSE);
			ft_rotate(a, &(ps->actions), TRUE);
			(ps->next_min)++;
			reset_position(a, b, ps, i);
			return (TRUE);
		}
		prev = prev->prev;
		i++;
	}
	return (FALSE);
}
