/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:44:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 01:46:35 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rev_rotate(t_blist **stack, t_list **actions, char *action)
{
	t_list	*new;

	if (stack && actions && action)
	{
		*stack = (*stack)->prev;
		new = ft_lstnew(action);
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
