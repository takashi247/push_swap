/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:40:59 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 11:20:54 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_quick_sort(t_blist **base, t_blist **sub, t_ps *ps)
{
	int		size;

	while (ps->next_min != ps->all_size)
	{
		ft_initialize_sub(base, sub, ps);
		size = ft_blstsize(*sub);
		while (MAX_SORTSIZE < size)
		{
			ft_halve_stack(sub, base, ps, FALSE);
			size = ft_blstsize(*sub);
		}
		ps->sub_size = size;
		ft_sort_stack(sub, base, ps, FALSE);
		if (*sub)
			ft_clear_sub(sub, base, ps, size);
		else if (size)
			ft_clear_base(base, ps, size);
	}
}
