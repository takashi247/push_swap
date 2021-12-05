/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:05:22 by tnishina          #+#    #+#             */
/*   Updated: 2021/12/05 16:27:00 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_stack(t_blist **base, t_blist **sub, t_ps *ps, t_bool base_is_a)
{
	if (base && sub && ps)
	{
		if (ps->sub_size == 1 || ft_is_sorted(*base))
			return ;
		else if (ps->sub_size == 2)
			ft_sort_two(base, sub, &(ps->actions), base_is_a);
		else if (ps->sub_size == 3)
			ft_sort_three(base, sub, &(ps->actions), base_is_a);
		else if (ps->sub_size == 4)
			ft_sort_four(base, sub, &(ps->actions), base_is_a);
		else if (ps->sub_size == 5)
			ft_sort_five(base, sub, &(ps->actions), base_is_a);
		else
			ft_sort_more(base, sub, ps);
	}
}
