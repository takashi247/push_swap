/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:34:01 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 10:48:00 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	add_action(t_list **actions, t_bool is_from_a)
{
	t_list	*new;

	if (is_from_a)
		new = ft_lstnew("pb");
	else
		new = ft_lstnew("pa");
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(actions, new);
	return (TRUE);
}

void
	ft_push_stack(t_blist **from, t_blist **to)
{
	int		from_size;
	t_blist	*new;
	t_blist	*prev;

	if (!from || !(*from))
		return ;
	from_size = ft_blstsize(*from);
	prev = (*from)->prev;
	*from = (*from)->next;
	new = (*from)->prev;
	new->prev = new;
	new->next = new;
	prev->next = *from;
	(*from)->prev = prev;
	if (from_size == 1)
		*from = NULL;
	ft_blstadd_front(to, new);
}

void
	ft_push(t_blist **from, t_blist **to, t_list **actions, t_bool is_from_a)
{
	t_list	*last;

	ft_push_stack(from, to);
	last = ft_lstlast(*actions);
	if (last && ((is_from_a && !ft_strncmp(last->content, "pa", 3))
			|| (!is_from_a && !ft_strncmp(last->content, "pb", 3))))
		ft_delete_action(actions);
	else
		add_action(actions, is_from_a);
}
