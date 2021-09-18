/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:05:22 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 23:45:13 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	sort_hundred(t_blist **stack, t_list **actions)
{
	(void)stack;
	(void)actions;
	return ;
}

void
	sort_more(t_blist **stack, t_list **actions)
{
	(void)stack;
	(void)actions;
	return ;
}

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
	ft_sort_stack(t_blist **stack_a, t_list **actions, const int size_of_stack)
{
	if (stack_a && actions)
	{
		if (size_of_stack == 1 || is_sorted(*stack_a))
			return ;
		else if (size_of_stack == 2)
			ft_sort_two(stack_a, actions);
		else if (size_of_stack == 3)
			ft_sort_three(stack_a, actions);
		else if (size_of_stack == 4)
			ft_sort_four(stack_a, actions);
		else if (size_of_stack == 5)
			ft_sort_five(stack_a, actions);
		else if (size_of_stack <= 100)
			sort_hundred(stack_a, actions);
		else
			sort_more(stack_a, actions);
	}
}
