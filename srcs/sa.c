/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:16:17 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/20 20:48:15 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_swap(t_blist **stack, t_list **actions, t_bool is_a)
{
	t_blist	*tmp;
	t_list	*new;

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
	if (is_a)
		new = ft_lstnew("sa");
	else
		new = ft_lstnew("sb");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
}
