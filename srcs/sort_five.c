/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:40:57 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 11:06:03 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	double_rotate(t_blist **stack, t_list **actions, t_bool stack_is_a)
{
	ft_rotate(stack, actions, stack_is_a);
	ft_rotate(stack, actions, stack_is_a);
}

static void
	push_n_rotate(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	const int	max_i = ft_get_index(*base, ft_get_max(*base));
	const int	sec_max_i = ft_get_index(*base,
					ft_get_second_max(*base, max_i));

	ft_push(base, sub, actions, base_is_a);
	if (max_i == 2 || sec_max_i == 2)
		ft_rotate(base, actions, base_is_a);
	else if (max_i == 3 || sec_max_i == 3)
		double_rotate(base, actions, base_is_a);
	else if (max_i == 4 || sec_max_i == 4)
		ft_rev_rotate(base, actions, base_is_a);
	ft_push(base, sub, actions, base_is_a);
	if (*(int *)(*sub)->content > *(int *)(*sub)->next->content)
		ft_swap(sub, actions, !base_is_a);
}

static void
	rotate_n_push(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	const int	max_i = ft_get_index(*base, ft_get_max(*base));
	const int	sec_max_i = ft_get_index(*base,
					ft_get_second_max(*base, max_i));

	if (max_i == 4 || sec_max_i == 4)
		ft_rev_rotate(base, actions, base_is_a);
	else
		ft_rotate(base, actions, base_is_a);
	if (max_i == 1 || sec_max_i == 1)
		ft_push(base, sub, actions, base_is_a);
	if ((max_i == 1 && sec_max_i == 3) || (max_i == 3 && sec_max_i == 1)
		|| (max_i == 1 && sec_max_i == 4) || (max_i == 4 && sec_max_i == 1)
		|| (max_i == 2 && sec_max_i == 3) || (max_i == 3 && sec_max_i == 2))
		ft_rotate(base, actions, base_is_a);
	if ((max_i == 2 && sec_max_i == 3) || (max_i == 3 && sec_max_i == 2)
		|| (max_i == 2 && sec_max_i == 4) || (max_i == 4 && sec_max_i == 2)
		|| (max_i == 3 && sec_max_i == 4) || (max_i == 4 && sec_max_i == 3))
		ft_push(base, sub, actions, base_is_a);
	if ((max_i == 2 && sec_max_i == 4) || (max_i == 4 && sec_max_i == 2))
		double_rotate(base, actions, base_is_a);
	else if ((max_i == 3 && sec_max_i == 4) || (max_i == 4 && sec_max_i == 3))
		ft_rev_rotate(base, actions, base_is_a);
	ft_push(base, sub, actions, base_is_a);
	if (*(int *)(*sub)->content > *(int *)(*sub)->next->content)
		ft_swap(sub, actions, !base_is_a);
}

static void
	push_maxs(t_blist **base, t_blist **sub, t_list **actions, t_bool base_is_a)
{
	const int	max_i = ft_get_index(*base, ft_get_max(*base));
	const int	sec_max_i = ft_get_index(*base,
					ft_get_second_max(*base, max_i));

	if (max_i == 0 || sec_max_i == 0)
		push_n_rotate(base, sub, actions, base_is_a);
	else
		rotate_n_push(base, sub, actions, base_is_a);
}

void
	ft_sort_five(t_blist **base, t_blist **sub, t_list **actions,
		t_bool base_is_a)
{
	int		i;

	if (!base_is_a && ft_is_rev_sorted(*base))
	{
		i = -1;
		while (++i < 5)
			ft_push(base, sub, actions, base_is_a);
	}
	else
	{
		push_maxs(base, sub, actions, base_is_a);
		if (base_is_a)
		{
			ft_sort_three(base, sub, actions, base_is_a);
			ft_push(sub, base, actions, !base_is_a);
			ft_rotate(base, actions, base_is_a);
			ft_push(sub, base, actions, !base_is_a);
			ft_rotate(base, actions, base_is_a);
		}
		else
			ft_rev_sort_n_push_three(base, sub, actions, base_is_a);
	}
}
