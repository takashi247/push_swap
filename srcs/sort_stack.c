/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:05:22 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/10 01:05:54 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	if (a && b && ps)
	{
		if (ps->sub_size == 1 || ft_is_sorted(*a))
			return ;
		else if (ps->sub_size == 2)
			ft_sort_two(a, b, &(ps->actions), is_a);
		else if (ps->sub_size == 3)
			ft_sort_three(a, b, &(ps->actions), is_a);
		else if (ps->sub_size == 4)
			ft_sort_four(a, b, &(ps->actions), is_a);
		else if (ps->sub_size == 5)
			ft_sort_five(a, b, &(ps->actions), is_a);
		else
			ft_quick_sort(a, b, ps);
	}
}
