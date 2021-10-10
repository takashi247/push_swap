/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:16:17 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/10 18:51:30 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_swap_stack(t_blist **stack)
{
	t_blist	*tmp;

	if (!stack || !(*stack))
		return ;
	if (ft_blstsize(*stack) == 2)
		*stack = (*stack)->next;
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		(*stack)->prev = tmp->prev;
		tmp->prev->next = *stack;
		tmp->prev = *stack;
		tmp->next->prev = tmp;
	}
}

void
	ft_swap(t_blist **stack, t_list **actions, t_bool is_a)
{
	t_list	*new;
	t_list	*last;

	ft_swap_stack(stack);
	last = ft_lstlast(*actions);
	if (last && ((is_a && !ft_strncmp(last->content, "sb", 3))
			|| (!is_a && !ft_strncmp(last->content, "sa", 3))))
	{
		ft_delete_action(actions);
		new = ft_lstnew("ss");
	}
	else if (is_a)
		new = ft_lstnew("sa");
	else
		new = ft_lstnew("sb");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
}
