/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:41:49 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/23 18:09:09 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rotate(t_blist **stack, t_list **actions, t_bool is_a)
{
	t_list	*new;
	t_list	*last;

	if (stack && actions)
	{
		*stack = (*stack)->next;
		last = ft_lstlast(*actions);
		if (last && ((is_a && !ft_strncmp(last->content, "rb", 3))
				|| (!is_a && !ft_strncmp(last->content, "ra", 3))))
		{
			ft_delete_action(actions);
			new = ft_lstnew("rr");
		}
		else if (is_a)
			new = ft_lstnew("ra");
		else
			new = ft_lstnew("rb");
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
