/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:37:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 18:04:52 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_two(t_blist **stack, t_list **actions, char c)
{
	const int	top = *(int *)(*stack)->content;
	const int	bottom = *(int *)(*stack)->next->content;

	if (top > bottom)
		ft_swap(stack, actions, c);
}
