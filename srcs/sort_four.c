/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:32:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 20:40:25 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_min(t_blist **stack_a, t_blist **stack_b, t_list **actions)
{
	const int	min_i = ft_get_min_index(*stack_a);

	if (min_i == 1)
		ft_rotate(stack_a, actions, 'A');
	else if (min_i == 2)
	{
		ft_rotate(stack_a, actions, 'A');
		ft_rotate(stack_a, actions, 'A');
	}
	else if (min_i == 3)
		ft_rev_rotate(stack_a, actions, 'A');
	ft_push(stack_a, stack_b, actions, 'B');
}

void
	ft_sort_four(t_blist **stack_a, t_list **actions)
{
	t_blist	*stack_b;

	stack_b = NULL;
	push_min(stack_a, &stack_b, actions);
	ft_sort_three(stack_a, actions);
	ft_push(&stack_b, stack_a, actions, 'A');
}
