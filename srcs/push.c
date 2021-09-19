/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:34:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 16:25:47 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_push(t_blist **from, t_blist **to, t_list **actions, char c)
{
	t_list	*new;
	t_blist	*new_b;
	t_blist	*prev;
	int		*num;

	if (from && to && actions)
	{
		num = (int *)malloc(sizeof(int));
		if (num)
			*num = *(int *)(*from)->content;
		new_b = ft_blstnew(num);
		if (!new_b)
			exit(EXIT_FAILURE);
		prev = (*from)->prev;
		*from = (*from)->next;
		ft_blstdelone((*from)->prev, free);
		(*from)->prev = prev;
		(*from)->prev->next = *from;
		ft_blstadd_front(to, new_b);
		if (c == 'A')
			new = ft_lstnew("pa");
		else
			new = ft_lstnew("pb");
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_back(actions, new);
	}
}
