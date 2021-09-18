/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:41:49 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 01:44:39 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rotate(t_blist **stack, t_list **actions, char *action)
{
	t_list	*new;

	if (stack && actions && action)
	{
		*stack = (*stack)->next;
		new = ft_lstnew(action);
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
