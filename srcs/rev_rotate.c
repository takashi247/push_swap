/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:44:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 10:35:00 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	add_rrx(t_list *last, t_list **actions, t_bool stack_is_a)
{
	t_list	*new;

	if (last && ((stack_is_a && !ft_strncmp(last->content, "rrb", 4))
			|| (!stack_is_a && !ft_strncmp(last->content, "rra", 4))))
	{
		ft_delete_action(actions);
		new = ft_lstnew("rrr");
	}
	else if (stack_is_a)
		new = ft_lstnew("rra");
	else
		new = ft_lstnew("rrb");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
}

void
	ft_rev_rotate(t_blist **stack, t_list **actions, t_bool stack_is_a)
{
	t_list	*new;
	t_list	*last;

	if (stack && actions)
	{
		if (*stack)
			*stack = (*stack)->prev;
		last = ft_lstlast(*actions);
		if (last && ((stack_is_a && !ft_strncmp(last->content, "ra", 3))
				|| (!stack_is_a && !ft_strncmp(last->content, "rb", 3))))
			ft_delete_action(actions);
		else if (last && !ft_strncmp(last->content, "rr", 3))
		{
			ft_delete_action(actions);
			if (stack_is_a)
				new = ft_lstnew("rb");
			else
				new = ft_lstnew("ra");
			if (!new)
				exit(EXIT_FAILURE);
			ft_lstadd_back(actions, new);
		}
		else
			add_rrx(last, actions, stack_is_a);
	}
}
