/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:54:31 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:28:01 by tnishina         ###   ########.fr       */
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
	double_push_from_tail(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	if (!a || !*a || !b || !*b || !ps)
		return ;
	ft_rev_rotate(a, &(ps->actions), is_a);
	ft_push(a, b, &(ps->actions), is_a);
	ft_rev_rotate(a, &(ps->actions), is_a);
	ft_push(a, b, &(ps->actions), is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ps->next_min += 2;
}

static void
	add_p_size(t_ps *ps, int count)
{
	int		*p_size;
	t_list	*new;

	p_size = (int *)malloc(sizeof(int));
	if (p_size)
		*p_size = count;
	new = ft_lstnew(p_size);
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_front(&(ps->p_sizes), new);
}

void
	ft_halve_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int			i;
	int			count;

	ps->pivot = (ft_get_max(*a) + ft_get_min(*a)) / 2;
	ps->next_pivot = ps->pivot / 2;
	ps->size_a = ft_blstsize(*a);
	i = -1;
	count = 0;
	while (++i < ps->size_a)
	{
		if (!is_a && is_double_pushable_from_tail(*a, ps))
			double_push_from_tail(a, b, ps, is_a);
		else if (!is_a && ft_search_next_min(a, b, ps))
			continue ;
		else if (*a)
			count += ft_is_pushed_to_a(a, b, ps, is_a);
	}
	if (count)
		add_p_size(ps, count);
	if (is_a)
		ft_reset_stack_position(a, b, ps, is_a);
}
