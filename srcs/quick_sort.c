/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:40:59 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:31:12 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_quick_sort(t_blist **a, t_blist **b, t_ps *ps)
{
	int		size;

	while (ps->next_min != ps->all_size)
	{
		ft_initialize_b(a, b, ps);
		size = ft_blstsize(*b);
		while (MAX_SORTSIZE < size)
		{
			ft_halve_stack(b, a, ps, FALSE);
			size = ft_blstsize(*b);
		}
		ps->sub_size = size;
		ft_sort_stack(b, a, ps, FALSE);
		if (*b)
			ft_clear_b(b, a, ps, size);
		else if (size)
			ft_clear_a(a, ps, size);
	}
}
