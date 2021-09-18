/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:05:22 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 01:50:00 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	sort_two(t_blist **stack, t_list **actions)
{
	const int	top = *(int *)(*stack)->content;
	const int	bottom = *(int *)(*stack)->next->content;

	if (top > bottom)
		ft_swap(stack, actions, "sa");
}

void
	sort_three(t_blist **stack, t_list **actions)
{
	const int	top = *(int *)(*stack)->content;
	const int	middle = *(int *)(*stack)->next->content;
	const int	bottom = *(int *)(*stack)->next->next->content;

	if (top > middle && bottom >= top)
		ft_swap(stack, actions, "sa");
	else if (top > middle && middle > bottom)
	{
		ft_swap(stack, actions, "sa");
		ft_rev_rotate(stack, actions, "rra");
	}
	else if (top >= bottom && bottom > middle)
		ft_rotate(stack, actions, "ra");
	else if (middle > bottom && bottom >= top)
	{
		ft_swap(stack, actions, "sa");
		ft_rotate(stack, actions, "ra");
	}
	else if (middle >= top && top > bottom)
		ft_rev_rotate(stack, actions, "rra");
}

void
	sort_five(t_blist **stack, t_list **actions)
{
	(void)stack;
	(void)actions;
	return ;
}

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

void
	ft_sort_stack(t_blist **stack_a, t_list **actions, const int size_of_stack)
{
	if (size_of_stack == 1)
		return ;
	else if (size_of_stack == 2)
		sort_two(stack_a, actions);
	else if (size_of_stack == 3)
		sort_three(stack_a, actions);
	else if (size_of_stack <= 5)
		sort_five(stack_a, actions);
	else if (size_of_stack <= 100)
		sort_hundred(stack_a, actions);
	else
		sort_more(stack_a, actions);
}
