/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:39:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 19:11:43 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_three(t_blist **stack, t_list **actions, t_bool is_a)
{
	const int	top = *(int *)(*stack)->content;
	const int	middle = *(int *)(*stack)->next->content;
	const int	bottom = *(int *)(*stack)->next->next->content;

	if (top > middle && bottom > top)
		ft_swap(stack, actions, is_a);
	else if (top > middle && middle > bottom)
	{
		ft_swap(stack, actions, is_a);
		ft_rev_rotate(stack, actions, is_a);
	}
	else if (top > bottom && bottom > middle)
		ft_rotate(stack, actions, is_a);
	else if (middle > bottom && bottom > top)
	{
		ft_swap(stack, actions, is_a);
		ft_rotate(stack, actions, is_a);
	}
	else if (middle > top && top > bottom)
		ft_rev_rotate(stack, actions, is_a);
}
