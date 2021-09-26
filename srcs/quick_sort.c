/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:40:59 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/26 10:24:30 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool
	ft_search_next_min(t_blist **b, t_blist **a, t_ps *ps)
{
	int		i;
	int		j;
	t_blist	*current;

	if (!b || !(*b) || ft_blstsize(*b) < MIN_BLIST_SIZE)
		return (FALSE);
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
			return (TRUE);
		}
		current = current->prev;
		i++;
	}
	return (FALSE);
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
	}
	else
	{
		if (is_a)
		{
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
			ft_push(b, a, &(ps->actions), !is_a);
			ft_rotate(base, &(ps->actions), TRUE);
			(ps->next_min)++;
			(ps->n_sorted)++;
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
		else
		{
			ft_push(a, b, &(ps->actions), is_a);
			ft_rotate(base, &(ps->actions), TRUE);
			(ps->next_min)++;
			(ps->n_sorted)++;
		}
	}
}

static t_bool
	is_close_to_tail(t_blist *a, t_ps *ps, t_bool is_a)
{
	int		base_len;
	int		current_min_loc;

	if (!is_a)
		return (TRUE);
	else
	{
		current_min_loc = ft_get_index(a, ps->next_min - 1);
		base_len = ft_blstsize(a);
		if (current_min_loc == 0)
			return (TRUE);
		if ((base_len / 2 <= current_min_loc)
			&& (MAX_MOVE < base_len - current_min_loc))
			return (FALSE);
		else if ((current_min_loc < base_len / 2)
			&& (MAX_MOVE < current_min_loc))
			return (FALSE);
		return (TRUE);
	}
}

static t_bool
	is_double_pushable(t_blist *stack, t_ps *ps)
{
	int	first;
	int	second;

	if (!stack || !(stack->next))
		return (FALSE);
	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	if (first == ps->next_min + 1 && second == ps->next_min)
		return (TRUE);
	else
		return (FALSE);
}

static void
	double_push(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	ft_push(a, b, &(ps->actions), is_a);
	ft_push(a, b, &(ps->actions), is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ps->next_min += 2;
	ps->n_sorted += 2;
}

static t_bool
	is_double_pushable_from_tail(t_blist *stack, t_ps *ps)
{
	int	last;
	int	pre_last;

	if (!stack || !stack->prev || !stack->prev->prev || !ps)
		return (FALSE);
	last = *(int *)stack->prev->content;
	pre_last = *(int *)stack->prev->prev->content;
	if (pre_last == ps->next_min && last == ps->next_min + 1)
		return (TRUE);
	else
		return (FALSE);
}

static void
	double_push_from_tail(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	if (!a || !*a || !b || !*b || !ps)
		return ;
	ft_rev_rotate(a, &(ps->actions), is_a);
	ft_push(a, b, &(ps->actions), is_a);
	ft_rev_rotate(a, &(ps->actions), is_a);
	ft_push(a, b, &(ps->actions), is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ft_rotate(b, &(ps->actions), !is_a);
	ps->next_min += 2;
	ps->n_sorted += 2;
}

// static t_bool
// 	is_double_pushable_within_three(t_blist *stack, t_ps *ps)
// {
// 	int	first;
// 	int	second;
// 	int	third;
// 	int	fourth;

// 	if (!stack || !ps || ft_blstsize(stack) <= 2)
// 		return (FALSE);
// 	first = *(int *)stack->content;
// 	second = *(int *)stack->next->content;
// 	third = *(int *)stack->next->next->content;
// 	fourth = *(int *)stack->next->next->next->content;
// 	if (first == ps->next_min + 1)
// 	{
// 		if (second <= ps->pivot && third == ps->next_min)
// 			return (TRUE);
// 		else if (second <= ps->pivot && third <= ps->pivot
// 			&& fourth == ps->next_min)
// 			return (TRUE);
// 	}
// 	return (FALSE);
// }

static void
	halve_stack(t_blist **a, t_blist **b, t_ps *ps, t_bool is_a)
{
	int			size_a;
	t_list		*new;
	int			*p_size;
	int			i;
	int			min_loc;
	int			count;
	int			next_min_loc;
	int			size_b;

	ps->pivot = (ft_get_max(*a) + ft_get_min(*a)) / 2;
	ps->next_pivot = ps->pivot / 2;
	i = -1;
	size_a = ft_blstsize(*a);
	count = 0;
	while (++i < size_a)
	{
		if (!is_a && is_double_pushable_from_tail(*a, ps))
		{
			double_push_from_tail(a, b, ps, is_a);
			continue ;
		}
		if (!is_a && ft_search_next_min(a, b, ps))
			continue ;
		if (*a)
		{
			if (*(int *)(*a)->content == ps->next_min
				&& is_close_to_tail(*a, ps, is_a))
				rotate_n_keep(a, b, ps, is_a);
			else if (!is_a && is_double_pushable(*a, ps))
				double_push(a, b, ps, is_a);
			else if ((is_a && *(int *)(*a)->content <= ps->pivot))
				// || (!is_a && is_double_pushable_within_three(*a, ps)))
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
					if (*b && *(int *)(*b)->content > ps->next_pivot)
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
		next_min_loc = ft_get_index(*b, ps->next_min);
		size_a = ft_blstsize(*a);
		size_b = ft_blstsize(*b);
		i = 0;
		if (min_loc < size_a * 2 / 3)
		{
			while (i < min_loc + 1)
			{
				ft_rotate(a, &(ps->actions), is_a);
				if (*b && next_min_loc <= size_b * 2 / 3
					&& *(int *)(*b)->content != ps->next_min)
					ft_rotate(b, &(ps->actions), !is_a);
				i++;
			}
		}
		else
		{
			while (i < size_a - min_loc - 1)
			{
				ft_rev_rotate(a, &(ps->actions), is_a);
				if (*b && size_b / 2 < next_min_loc
					&& *(int *)(*b)->content != ps->next_min)
					ft_rev_rotate(b, &(ps->actions), !is_a);
				i++;
			}
		}
	}
}

static t_bool
	is_next_min_in_head_or_tail(t_blist **b, t_blist **a, t_ps *ps)
{
	if (!a || !*a || !b || !*b)
		return (FALSE);
	if (*(int *)(*b)->prev->content == ps->next_min)
	{
		if (2 <= ft_blstsize(*b))
			ft_rev_rotate(b, &(ps->actions), FALSE);
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
		(ps->next_min)++;
		(ps->n_sorted)++;
		return (TRUE);
	}
	else if (*(int *)(*b)->content == ps->next_min)
	{
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
		(ps->next_min)++;
		(ps->n_sorted)++;
		return (TRUE);
	}
	else if (*(int *)(*b)->next->content == ps->next_min)
	{
		if (2 <= ft_blstsize(*b))
			ft_rotate(b, &(ps->actions), FALSE);
		ft_push(b, a, &(ps->actions), FALSE);
		ft_rotate(a, &(ps->actions), TRUE);
		(ps->next_min)++;
		(ps->n_sorted)++;
		return (TRUE);
	}
	return (FALSE);
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
			if (is_next_min_in_head_or_tail(b, a, ps))
				continue ;
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
		if (*(int *)(*a)->content == ps->next_min)
		{
			ft_rotate(a, &(ps->actions), TRUE);
			(ps->n_sorted)++;
			(ps->next_min)++;
		}
		else
			(*(int *)ps->p_sizes->content)++;
		i++;
	}
	*b = NULL;
}

void
	ft_quick_sort(t_blist **a, t_blist **b, t_ps *ps)
{
	int		size;
	int		i;
	int		*p_size;
	t_list	*new;

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
				if (*(int *)(*a)->content == ps->next_min)
				{
					ft_rotate(a, &ps->actions, TRUE);
					(ps->next_min)++;
					(ps->n_sorted)++;
					i++;
				}
				else
				{
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
					break ;
				}
			}
		}
	}
}
