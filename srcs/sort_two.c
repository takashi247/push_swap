/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:37:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 10:13:05 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_two(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	const int	top = *(int *)(*base)->content;
	const int	bottom = *(int *)(*sub)->next->content;
	int			i;

	if (!base_is_a && ft_is_rev_sorted(*base))
	{
		i = 0;
		while (i < 2)
		{
			ft_push(base, sub, actions, base_is_a);
			i++;
		}
	}
	else if (top > bottom)
		ft_swap(base, actions, base_is_a);
}
