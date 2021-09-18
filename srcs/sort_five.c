/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:40:57 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 23:44:38 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_n_rotate(t_blist **a, t_blist **b, t_list **actions, int max_n_min[2])
{
	ft_push(a, b, actions, 'B');
	if (max_n_min[0] == 2 || max_n_min[1] == 2)
	{
		ft_rotate(a, actions, 'A');
	}
	else if (max_n_min[0] == 3 && max_n_min[1] == 3)
	{
		ft_rotate(a, actions, 'A');
		ft_rotate(a, actions, 'A');
	}
	else if (max_n_min[0] == 4 && max_n_min[1] == 4)
	{
		ft_rev_rotate(a, actions, 'A');
		ft_rev_rotate(a, actions, 'A');
	}
	ft_push(a, b, actions, 'B');
}

static void
	rotate_n_push(t_blist **a, t_blist **b, t_list **actions, int max_n_min[2])
{
	const int	max_i = max_n_min[0];
	const int	min_i = max_n_min[1];

	if (max_i == 4 || min_i == 4)
		ft_rev_rotate(a, actions, 'A');
	else
		ft_rotate(a, actions, 'A');
	if (max_i == 1 || min_i == 1)
		ft_push(a, b, actions, 'B');
	if ((max_i == 1 && min_i == 3) || (max_i == 3 && min_i == 1)
		|| (max_i == 1 && min_i == 4) || (max_i == 4 && min_i == 1)
		|| (max_i == 2 && min_i == 3) || (max_i == 3 && min_i == 2))
		ft_rotate(a, actions, 'A');
	if ((max_i == 2 && min_i == 3) || (max_i == 3 && min_i == 2)
		|| (max_i == 2 && min_i == 4) || (max_i == 4 && min_i == 2)
		|| (max_i == 3 && min_i == 4) || (max_i == 4 && min_i == 3))
		ft_push(a, b, actions, 'B');
	if ((max_i == 2 && min_i == 4) || (max_i == 4 && min_i == 2))
	{
		ft_rotate(a, actions, 'A');
		ft_rotate(a, actions, 'A');
	}
	else if ((max_i == 3 && min_i == 4) || (max_i == 4 && min_i == 3))
		ft_rev_rotate(a, actions, 'A');
	ft_push(a, b, actions, 'B');
}

static void
	push_max_min(t_blist **stack_a, t_blist **stack_b, t_list **actions)
{
	int	max_n_min[2];

	max_n_min[0] = ft_get_max_index(*stack_a);
	max_n_min[1] = ft_get_min_index(*stack_a);
	if (max_n_min[0] == 0 || max_n_min[1] == 0)
		push_n_rotate(stack_a, stack_b, actions, max_n_min);
	else
		rotate_n_push(stack_a, stack_b, actions, max_n_min);
}

void
	ft_sort_five(t_blist **stack_a, t_list **actions)
{
	t_blist	*stack_b;
	int		top;
	int		bottom;

	stack_b = NULL;
	push_max_min(stack_a, &stack_b, actions);
	ft_sort_three(stack_a, actions);
	top = *(int *)stack_b->content;
	bottom = *(int *)stack_b->next->content;
	if (top > bottom)
	{
		ft_push(&stack_b, stack_a, actions, 'A');
		ft_rotate(stack_a, actions, 'A');
		ft_push(&stack_b, stack_a, actions, 'A');
	}
	else
	{
		ft_push(&stack_b, stack_a, actions, 'A');
		ft_push(&stack_b, stack_a, actions, 'A');
		ft_rotate(stack_a, actions, 'A');
	}
}
