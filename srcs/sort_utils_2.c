/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:32:42 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:48:45 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool
	ft_is_rev_sorted(t_blist *stack)
{
	int			i;
	const int	n = ft_blstsize(stack);

	i = 0;
	while (i < n - 1)
	{
		if (*(int *)stack->content < *(int *)stack->next->content)
			return (FALSE);
		stack = stack->next;
		i++;
	}
	return (TRUE);
}

int
	ft_get_second_max(t_blist *stack, int max_i)
{
	int			i;
	const int	n = ft_blstsize(stack);
	int			second_max;

	if (max_i != 0)
	{
		i = 0;
		second_max = *(int *)stack->content;
	}
	else
	{
		i = 1;
		second_max = *(int *)stack->next->content;
	}
	while (i < n)
	{
		if (i != max_i && second_max < *(int *)stack->content)
			second_max = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (second_max);
}
