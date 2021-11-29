/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:42:48 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 14:30:34 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	stop_rotating(t_ps *ps, int size, int i)
{
	int		*p_size;
	t_list	*new;

	if (ps->batch_size_lst)
		*(int *)ps->batch_size_lst->content += size - i;
	else
	{
		p_size = (int *)malloc(sizeof(int));
		*p_size = size - i;
		new = ft_lstnew(p_size);
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_front(&(ps->batch_size_lst), new);
	}
}

void
	ft_clear_base(t_blist **base, t_ps *ps, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (*(int *)(*base)->content == ps->next_min)
		{
			ft_rotate(base, &ps->actions, TRUE);
			(ps->next_min)++;
			i++;
		}
		else
		{
			stop_rotating(ps, size, i);
			break ;
		}
	}
}
