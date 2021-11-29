/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:54:31 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 23:27:47 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_double_pushable_from_tail(t_blist *stack, t_ps *ps)
{
	int	last;
	int	pre_last;

	if (!stack || !stack->prev || !stack->prev->prev || !ps)
		return (FALSE);
	last = *(int *)stack->prev->content;
	pre_last = *(int *)stack->prev->prev->content;
	if (pre_last == ps->next_min && last == ps->next_min + 1)
		return (TRUE);
	else
		return (FALSE);
}

static void
	double_push_from_tail(t_blist **base, t_blist **sub, t_ps *ps,
		t_bool base_is_a)
{
	if (!base || !*base || !sub || !*sub || !ps)
		return ;
	ft_rev_rotate(base, &(ps->actions), base_is_a);
	ft_push(base, sub, &(ps->actions), base_is_a);
	ft_rev_rotate(base, &(ps->actions), base_is_a);
	ft_push(base, sub, &(ps->actions), base_is_a);
	ft_rotate(sub, &(ps->actions), !base_is_a);
	ft_rotate(sub, &(ps->actions), !base_is_a);
	ps->next_min += 2;
}

static void
	add_batch_size(t_ps *ps, int batch_size)
{
	int		*size;
	t_list	*new;

	size = (int *)malloc(sizeof(int));
	if (size)
		*size = batch_size;
	new = ft_lstnew(size);
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_front(&(ps->batch_size_lst), new);
}

void
	ft_halve_stack(t_blist **base, t_blist **sub, t_ps *ps, t_bool base_is_a)
{
	int	i;
	int	batch_size;

	ps->pivot = (ft_get_max(*base) + ft_get_min(*base)) / 2;
	ps->next_pivot = ps->pivot / 2;
	ps->size_base = ft_blstsize(*base);
	i = -1;
	batch_size = 0;
	while (++i < ps->size_base)
	{
		if (!base_is_a && is_double_pushable_from_tail(*base, ps))
		{
			double_push_from_tail(base, sub, ps, base_is_a);
			if (i < 2)
				ps->size_base -= 2 - i;
		}
		else if (!base_is_a && ft_search_next_min(base, sub, ps))
			continue ;
		else if (*base)
			batch_size += ft_is_added_to_batch(base, sub, ps, base_is_a);
	}
	if (batch_size)
		add_batch_size(ps, batch_size);
	if (base_is_a)
		ft_reset_stack_position(base, sub, ps, base_is_a);
}
