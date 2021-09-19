/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:44:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 19:09:18 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rev_rotate(t_blist **stack, t_list **actions, t_bool is_a)
{
	t_list	*new;

	if (stack && actions)
	{
		*stack = (*stack)->prev;
		if (is_a)
			new = ft_lstnew("rra");
		else
			new = ft_lstnew("rrb");
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
