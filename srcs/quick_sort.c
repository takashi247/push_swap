/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:40:59 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/25 20:09:44 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_search_next_min(t_blist **b, t_blist **a, t_ps *ps)
{
	int		i;
	int		j;
	t_blist	*current;

	if (!b || !(*b))
		return ;
	i = 0;
	current = (*b)->prev;
	while (current && i < MIN_SEARCH)
	{
		if (*(int *)current->content == ps->next_min)
		{
			j = 0;
			while (j < i + 1)
			{
				ft_rev_rotate(b, &(ps->actions), FALSE);
				j++;
			}
			ft_push(b, a, &(ps->actions), FALSE);
			ft_rotate(a, &(ps->actions), TRUE);
			(ps->next_min)++;
			(ps->n_sorted)++;
			j = 0;
			while (j < i)
			{
				if (*(int *)(*b)->content == ps->next_min)
				{
					ft_push(b, a, &(ps->actions), FALSE);
					ft_rotate(a, &(ps->actions), TRUE);
					(ps->next_min)++;
					(ps->n_sorted)++;
					i--;
				}
				else
				{
					ft_rotate(b, &(ps->actions), FALSE);
					j++;
				}
			}
			return ;
		}
		current = current->prev;
		i++;
	}
}

static void
	rotate_n_keep(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int		i;
	int		current_min;
	int		len;
	int		count;
	t_blist	**base;

	if (is_a)
		base = a;
	else
		base = b;
	if (!ps->next_min)
	{
		ft_rotate(a, &(ps->actions), is_a);
		(ps->next_min)++;
		(ps->n_sorted)++;
		// ft_search_next_min(b, a, ps, NULL);
	}
	else
	{
		if (is_a)
			ft_push(a, b, &(ps->actions), is_a);
		current_min = ft_get_index(*base, ps->next_min - 1);
		len = ft_blstsize(*base);
		if (len / 2 <= current_min)
		{
			count = len - ++current_min;
			i = 0;
			while (i < count)
			{
				ft_rev_rotate(base, &(ps->actions), TRUE);
				i++;
			}
		}
		else
		{
			count = current_min + 1;
			i = 0;
			while (i < count)
			{
				ft_rotate(base, &(ps->actions), TRUE);
				i++;
			}
		}
		if (is_a)
		{
			ft_push(b, a, &(ps->actions), !is_a);
			ft_rotate(base, &(ps->actions), TRUE);
			(ps->next_min)++;
			(ps->n_sorted)++;
			// ft_search_next_min(b, a, ps, &count);
		}
		else
		{
			ft_push(a, b, &(ps->actions), is_a);
			ft_rotate(base, &(ps->actions), TRUE);
			(ps->next_min)++;
			(ps->n_sorted)++;
		}
		i = 0;
		len = ft_blstsize(*base);
		if (len / 2 <= current_min)
		{
			while (i < count)
			{
				ft_rotate(base, &(ps->actions), TRUE);
				i++;
			}
		}
		else
		{
			while (i < count + 1)
			{
				ft_rev_rotate(base, &(ps->actions), TRUE);
				i++;
			}
		}
	}
}

static t_bool
	is_close_to_tail(t_blist *a, t_blist *b, t_ps *ps, t_bool is_a)
{
	t_blist	*base;
	int		base_len;
	int		current_min_loc;

	if (is_a)
		base = a;
	else
		base = b;
	current_min_loc = ft_get_index(base, ps->next_min - 1);
	base_len = ft_blstsize(base);
	if ((base_len / 2 <= current_min_loc)
		&& (MAX_MOVE < base_len - current_min_loc))
		return (FALSE);
	else if ((current_min_loc < base_len / 2)
		&& (MAX_MOVE < current_min_loc))
		return (FALSE);
	return (TRUE);
}

static void
	halve_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int			size_a;
	t_list		*new;
	int			*p_size;
	int			i;
	int			min_loc;
	int			count;

	ps->pivot = (ft_get_max(*a) + ft_get_min(*a)) / 2;
	ps->next_pivot = ps->pivot / 2;
	i = -1;
	size_a = ft_blstsize(*a);
	count = 0;
	while (++i < size_a)
	{
		if (!is_a)
			ft_search_next_min(a, b, ps);
		if (*a)
		{
			if (*(int *)(*a)->content == ps->next_min
				&& is_close_to_tail(*a, *b, ps, is_a))
				rotate_n_keep(a, b, ps, is_a);
			else if (is_a && *(int *)(*a)->content <= ps->pivot)
				ft_push(a, b, &(ps->actions), is_a);
			else if (!is_a && ps->pivot < *(int *)(*a)->content)
			{
				ft_push(a, b, &(ps->actions), is_a);
				count++;
			}
			else
			{
				ft_rotate(a, &(ps->actions), is_a);
				if (is_a)
				{
					if (*b && *(int *)(*b)->content <= ps->next_pivot)
						ft_rotate(b, &(ps->actions), !is_a);
					count++;
				}
			}
		}
	}
	p_size = (int *)malloc(sizeof(int));
	if (p_size)
		*p_size = count;
	new = ft_lstnew(p_size);
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_front(&(ps->p_sizes), new);
	if (is_a)
	{
		min_loc = ft_get_index(*a, ps->next_min - 1);
		size_a = ft_blstsize(*a);
		i = 0;
		if (min_loc < size_a / 2)
		{
			while (i < min_loc + 1)
			{
				ft_rotate(a, &(ps->actions), is_a);
				if (is_a && *b && *(int *)(*b)->content <= ps->next_pivot)
					ft_rotate(b, &(ps->actions), !is_a);
				i++;
			}
		}
		else
		{
			while (i < size_a - min_loc - 1)
			{
				ft_rev_rotate(a, &(ps->actions), is_a);
				i++;
			}
		}
	}
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
			if (*(int *)(*a)->content == ps->next_min)
			{
				ft_rotate(a, &(ps->actions), TRUE);
				(ps->next_min)++;
				(ps->n_sorted)++;
			}
			else if (*(int *)(*a)->next->content == ps->next_min
				&& *(int *)(*a)->content == ps->next_min + 1)
			{
				ft_swap(a, &(ps->actions), TRUE);
				ft_rotate(a, &(ps->actions), TRUE);
				(ps->next_min)++;
				(ps->n_sorted)++;
			}
			else
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
	int	len;

	if (*(int *)(*a)->prev->content != ps->next_min - 1)
	{
		i = ft_get_index(*a, ps->next_min - 1);
		len = ft_blstsize(*a);
		if (len / 2 <= i)
		{
			while (len - ++i)
				ft_rev_rotate(a, &(ps->actions), TRUE);
		}
		else
		{
			while (i + 1)
			{
				ft_rotate(a, &(ps->actions), TRUE);
				i--;
			}
		}
	}
	i = 0;
	while (i < size)
	{
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
		i++;
	}
	*b = NULL;
	ps->n_sorted += size;
	ps->next_min += size;
}

void
	ft_quick_sort(t_blist **a, t_blist **b, t_ps *ps)
{
	int	size;
	int	i;

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
		if (*b)
			clear_b(b, a, ps, size);
		else
		{
			i = 0;
			while (i < size)
			{
				ft_rotate(a, &ps->actions, TRUE);
				(ps->next_min)++;
				(ps->n_sorted)++;
				i++;
			}
		}
	}
}
