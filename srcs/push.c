/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:34:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 20:29:51 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_push(t_blist **from, t_blist **to, t_list **actions, t_bool is_a)
{
	t_list	*new;
	t_blist	*new_b;
	t_blist	*prev;
	int		*num;

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
	if (is_a)
		new = ft_lstnew("pb");
	else
		new = ft_lstnew("pa");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
}
