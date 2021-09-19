/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:40:57 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 18:34:58 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_n_rotate(t_blist **a, t_blist **b, t_list **actions, char c)
{
	const int	max_i = ft_get_max_index(*a);
	const int	min_i = ft_get_min_index(*a);
	char		c_pushed;

	if (c == 'A')
		c_pushed = 'B';
	else
		c_pushed = 'A';
	ft_push(a, b, actions, c_pushed);
	if (max_i == 2 || min_i == 2)
		ft_rotate(a, actions, c);
	else if (max_i == 3 || min_i == 3)
	{
		ft_rotate(a, actions, c);
		ft_rotate(a, actions, c);
	}
	else if (max_i == 4 || min_i == 4)
		ft_rev_rotate(a, actions, c);
	ft_push(a, b, actions, c_pushed);
}

static void
	rotate_n_push(t_blist **a, t_blist **b, t_list **actions, char c)
{
	const int	max_i = ft_get_max_index(*a);
	const int	min_i = ft_get_min_index(*a);
	char		c_pushed;

	if (c == 'A')
		c_pushed = 'B';
	else
		c_pushed = 'A';
	if (max_i == 4 || min_i == 4)
		ft_rev_rotate(a, actions, c);
	else
		ft_rotate(a, actions, c);
	if (max_i == 1 || min_i == 1)
		ft_push(a, b, actions, c_pushed);
	if ((max_i == 1 && min_i == 3) || (max_i == 3 && min_i == 1)
		|| (max_i == 1 && min_i == 4) || (max_i == 4 && min_i == 1)
		|| (max_i == 2 && min_i == 3) || (max_i == 3 && min_i == 2))
		ft_rotate(a, actions, c);
	if ((max_i == 2 && min_i == 3) || (max_i == 3 && min_i == 2)
		|| (max_i == 2 && min_i == 4) || (max_i == 4 && min_i == 2)
		|| (max_i == 3 && min_i == 4) || (max_i == 4 && min_i == 3))
		ft_push(a, b, actions, c_pushed);
	if ((max_i == 2 && min_i == 4) || (max_i == 4 && min_i == 2))
	{
		ft_rotate(a, actions, c);
		ft_rotate(a, actions, c);
	}
	else if ((max_i == 3 && min_i == 4) || (max_i == 4 && min_i == 3))
		ft_rev_rotate(a, actions, c);
	ft_push(a, b, actions, c_pushed);
}

static void
	push_max_min(t_blist **a, t_blist **b, t_list **actions, char c)
{
	const int	max_i = ft_get_max_index(*a);
	const int	min_i = ft_get_min_index(*a);

	if (max_i == 0 || min_i == 0)
		push_n_rotate(a, b, actions, c);
	else
		rotate_n_push(a, b, actions, c);
}

void
	ft_sort_five(t_blist **a, t_blist **b, t_list **actions, char c)
{
	int		top;
	int		bottom;

	push_max_min(a, b, actions, c);
	ft_sort_three(a, actions, c);
	top = *(int *)(*b)->content;
	bottom = *(int *)(*b)->next->content;
	if (top > bottom)
	{
		ft_push(b, a, actions, c);
		ft_rotate(a, actions, c);
		ft_push(b, a, actions, c);
	}
	else
	{
		ft_push(b, a, actions, c);
		ft_push(b, a, actions, c);
		ft_rotate(a, actions, c);
	}
}
