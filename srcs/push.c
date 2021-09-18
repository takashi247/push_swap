/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:34:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 17:08:30 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_push(t_blist **from, t_blist **to, t_list **actions, char c)
{
	t_list	*new;
	t_blist	*tmp;

	if (from && to && actions)
	{
		tmp = *from;
		*from = tmp->next;
		(*from)->prev = tmp->prev;
		tmp->prev->next = *from;
		tmp->next = tmp;
		tmp->prev = tmp;
		ft_blstadd_front(to, tmp);
		if (c == 'A')
			new = ft_lstnew("pa");
		else
			new = ft_lstnew("pb");
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
