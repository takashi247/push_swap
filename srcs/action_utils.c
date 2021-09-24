/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:01:09 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/23 18:01:37 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_delete_action(t_list **actions)
{
	t_list	*pre_last;
	t_list	*last;

	if (ft_lstsize(*actions) == 1)
	{
		ft_lstdelone(*actions, NULL);
		*actions = NULL;
	}
	else
	{
		pre_last = *actions;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		last = pre_last->next;
		pre_last->next = NULL;
		ft_lstdelone(last, NULL);
		last = NULL;
	}
}