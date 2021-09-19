/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:32:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 18:09:10 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_min(t_blist **stack_a, t_blist **stack_b, t_list **actions, char c)
{
	const int	min_i = ft_get_min_index(*stack_a);

	if (min_i == 1)
		ft_rotate(stack_a, actions, c);
	else if (min_i == 2)
	{
		ft_rotate(stack_a, actions, c);
		ft_rotate(stack_a, actions, c);
	}
	else if (min_i == 3)
		ft_rev_rotate(stack_a, actions, c);
	if (c == 'A')
		ft_push(stack_a, stack_b, actions, 'B');
	else
		ft_push(stack_a, stack_b, actions, 'A');
}

void
	ft_sort_four(t_blist **a, t_blist **b, t_list **actions, char c)
{
	push_min(a, b, actions, c);
	ft_sort_three(a, actions, c);
	ft_push(b, a, actions, c);
}
