/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:44:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/23 18:43:56 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rev_rotate(t_blist **stack, t_list **actions, t_bool is_a)
{
	t_list	*new;
	t_list	*last;

	if (stack && actions)
	{
		*stack = (*stack)->prev;
		last = ft_lstlast(*actions);
		if (last && ((is_a && !ft_strncmp(last->content, "rrb", 4))
				|| (!is_a && !ft_strncmp(last->content, "rra", 4))))
		{
			ft_delete_action(actions);
			new = ft_lstnew("rrr");
		}
		else if (is_a)
			new = ft_lstnew("rra");
		else
			new = ft_lstnew("rrb");
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
