/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:32:42 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/25 22:46:35 by tnishina         ###   ########.fr       */
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
