/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:39:47 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 11:40:05 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_three(t_blist **stack, t_list **actions)
{
	const int	top = *(int *)(*stack)->content;
	const int	middle = *(int *)(*stack)->next->content;
	const int	bottom = *(int *)(*stack)->next->next->content;

	if (top > middle && bottom > top)
		ft_swap(stack, actions, 'A');
	else if (top > middle && middle > bottom)
	{
		ft_swap(stack, actions, 'A');
		ft_rev_rotate(stack, actions, 'A');
	}
	else if (top > bottom && bottom > middle)
		ft_rotate(stack, actions, 'A');
	else if (middle > bottom && bottom > top)
	{
		ft_swap(stack, actions, 'A');
		ft_rotate(stack, actions, 'A');
	}
	else if (middle > top && top > bottom)
		ft_rev_rotate(stack, actions, 'A');
}
