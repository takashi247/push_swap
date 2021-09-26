/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:34:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/23 18:04:33 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	add_action(t_list **actions, t_bool is_a)
{
	t_list	*new;

	if (is_a)
		new = ft_lstnew("pb");
	else
		new = ft_lstnew("pa");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
	return (TRUE);
}

void
	ft_push(t_blist **from, t_blist **to, t_list **actions, t_bool is_a)
{
	t_blist	*new;
	t_blist	*prev;
	int		*num;
	t_list	*last;
	int		from_size;

	from_size = ft_blstsize(*from);
	num = (int *)malloc(sizeof(int));
	if (num)
		*num = *(int *)(*from)->content;
	new = ft_blstnew(num);
	if (!new)
		exit(EXIT_FAILURE);
	prev = (*from)->prev;
	*from = (*from)->next;
	ft_blstdelone((*from)->prev, free);
	(*from)->prev = prev;
	(*from)->prev->next = *from;
	if (from_size == 1)
		*from = NULL;
	ft_blstadd_front(to, new);
	last = ft_lstlast(*actions);
	if (last && ((is_a && !ft_strncmp(last->content, "pa", 3))
			|| (!is_a && !ft_strncmp(last->content, "pb", 3))))
		ft_delete_action(actions);
	else
		add_action(actions, is_a);
}
