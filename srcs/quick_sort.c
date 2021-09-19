/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:40:59 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/19 22:36:49 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	halve_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	const int	size_a = ft_blstsize(*a);
	const int	pivot = (ft_get_max(*a) + ft_get_min(*a)) / 2;
	t_list		*new;
	int			*p_size;
	int			i;

	i = 0;
	while (i < size_a)
	{
		if (is_a && *(int *)(*a)->content <= pivot)
			ft_push(a, b, &(ps->actions), is_a);
		else if (!is_a && pivot < *(int *)(*a)->content)
			ft_push(a, b, &(ps->actions), is_a);
		else
			ft_rotate(a, &(ps->actions), is_a);
		i++;
	}
	p_size = (int *)malloc(sizeof(int));
	if (p_size)
		*p_size = size_a / 2;
	new = ft_lstnew(p_size);
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_front(&(ps->p_sizes), new);
}

static void
	initialize_b(t_blist **a, t_blist **b, t_ps *ps)
{
	int		i;
	t_list	*tmp;

	if (!ps->p_sizes)
		halve_stack(a, b, ps, TRUE);
	else
	{
		i = 0;
		while (i < *(int *)ps->p_sizes->content)
		{
			ft_push(a, b, &(ps->actions), TRUE);
			i++;
		}
		tmp = ps->p_sizes;
		ps->p_sizes = ps->p_sizes->next;
		ft_lstdelone(tmp, free);
	}
}

static void
	clear_b(t_blist **b, t_blist **a, t_ps *ps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
		i++;
	}
	*b = NULL;
	ps->n_sorted += size;
}

void
	ft_quick_sort(t_blist **a, t_blist **b, t_ps *ps)
{
	int	size;

	while (ps->n_sorted != ps->all_size)
	{
		initialize_b(a, b, ps);
		size = ft_blstsize(*b);
		while (MAX_SORTSIZE < size)
		{
			halve_stack(b, a, ps, FALSE);
			size = ft_blstsize(*b);
		}
		ps->sub_size = size;
		ft_sort_stack(b, a, ps, FALSE);
		clear_b(b, a, ps, size);
	}
}
