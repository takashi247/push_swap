/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:41:49 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 10:42:41 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rotate(t_blist **stack, t_list **actions, char c)
{
	t_list	*new;

	if (stack && actions)
	{
		*stack = (*stack)->next;
		if (c == 'A')
			new = ft_lstnew("ra");
		else
			new = ft_lstnew("rb");
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
