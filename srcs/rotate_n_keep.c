/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_n_keep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:31:35 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:31:49 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	reset_position(t_blist **base, t_ps *ps, int *count)
{
	const int	current_min = ft_get_index(*base, ps->next_min - 1);
	const int	len = ft_blstsize(*base);
	int			i;

	if (len / 2 <= current_min)
	{
		*count = len - (current_min + 1);
		i = 0;
		while (i < *count)
		{
			ft_rev_rotate(base, &(ps->actions), TRUE);
			i++;
		}
	}
	else
	{
		*count = current_min + 1;
		i = 0;
		while (i < *count)
		{
			ft_rotate(base, &(ps->actions), TRUE);
			i++;
		}
	}
}

static void
	rotate_n_keep_a(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int			i;
	int			count;
	int			len;
	const int	current_min = ft_get_index(*(ps->base), ps->next_min - 1);

	ft_push(a, b, &(ps->actions), is_a);
	reset_position(ps->base, ps, &count);
	ft_push(b, a, &(ps->actions), !is_a);
	ft_rotate(ps->base, &(ps->actions), TRUE);
	(ps->next_min)++;
	i = -1;
	len = ft_blstsize(*(ps->base));
	if (len / 2 <= current_min)
	{
		while (++i < count)
			ft_rotate(ps->base, &(ps->actions), TRUE);
	}
	else
	{
		while (++i < count + 1)
			ft_rev_rotate(ps->base, &(ps->actions), TRUE);
	}
}

void
	ft_rotate_n_keep(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	if (is_a)
		ps->base = a;
	else
		ps->base = b;
	if (!ps->next_min)
	{
		ft_rotate(a, &(ps->actions), is_a);
		(ps->next_min)++;
	}
	else
	{
		if (is_a)
			rotate_n_keep_a(a, b, ps, is_a);
		else
		{
			ft_push(a, b, &(ps->actions), is_a);
			ft_rotate(ps->base, &(ps->actions), TRUE);
			(ps->next_min)++;
		}
	}
}
