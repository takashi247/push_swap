/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:05:22 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 19:09:48 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_sorted(t_blist *stack)
{
	int			i;
	const int	n = ft_blstsize(stack);

	i = 0;
	while (i < n - 1)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (FALSE);
		stack = stack->next;
		i++;
	}
	return (TRUE);
}

void
	ft_sort_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	if (a && b && ps)
	{
		if (ps->sub_size == 1 || is_sorted(*a))
			return ;
		else if (ps->sub_size == 2)
			ft_sort_two(a, &(ps->actions), is_a);
		else if (ps->sub_size == 3)
			ft_sort_three(a, &(ps->actions), is_a);
		else if (ps->sub_size == 4)
			ft_sort_four(a, b, &(ps->actions), is_a);
		else if (ps->sub_size == 5)
			ft_sort_five(a, b, &(ps->actions), is_a);
		else
			ft_quick_sort(a, b, ps);
	}
}
