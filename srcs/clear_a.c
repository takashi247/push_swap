/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:42:48 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/02 16:43:13 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	stop_rotating(t_ps *ps, int size, int i)
{
	int		*p_size;
	t_list	*new;

	if (ps->p_sizes)
		*(int *)ps->p_sizes->content += size - i;
	else
	{
		p_size = (int *)malloc(sizeof(int));
		*p_size = size - i;
		new = ft_lstnew(p_size);
		if (!new)
			exit(EXIT_FAILURE);
		ft_lstadd_front(&(ps->p_sizes), new);
	}
}

void
	ft_clear_a(t_blist **a, t_ps *ps, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (*(int *)(*a)->content == ps->next_min)
		{
			ft_rotate(a, &ps->actions, TRUE);
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
