/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:41:49 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 10:38:25 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	delete_n_add_after_rrr(t_list **actions, t_bool stack_is_a)
{
	t_list	*new;

	ft_delete_action(actions);
	if (stack_is_a)
		new = ft_lstnew("rrb");
	else
		new = ft_lstnew("rra");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
}

void
	add_rx(t_list *last, t_list **actions, t_bool stack_is_a)
{
	t_list	*new;

	if (last && ((stack_is_a && !ft_strncmp(last->content, "rb", 3))
			|| (!stack_is_a && !ft_strncmp(last->content, "ra", 3))))
	{
		ft_delete_action(actions);
		new = ft_lstnew("rr");
	}
	else if (stack_is_a)
		new = ft_lstnew("ra");
	else
		new = ft_lstnew("rb");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
}

void
	ft_rotate(t_blist **stack, t_list **actions, t_bool stack_is_a)
{
	t_list	*last;

	if (stack && actions)
	{
		if (*stack)
			*stack = (*stack)->next;
		last = ft_lstlast(*actions);
		if (last && ((stack_is_a && !ft_strncmp(last->content, "rra", 4))
				|| (!stack_is_a && !ft_strncmp(last->content, "rrb", 4))))
			ft_delete_action(actions);
		else if (last && !ft_strncmp(last->content, "rrr", 4))
			delete_n_add_after_rrr(actions, stack_is_a);
		else
			add_rx(last, actions, stack_is_a);
	}
}
