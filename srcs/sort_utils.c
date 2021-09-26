/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:27:04 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/20 00:42:52 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ft_get_max(t_blist *stack)
{
	int			i;
	const int	n = ft_blstsize(stack);
	int			max;

	i = 0;
	max = *(int *)stack->content;
	while (i < n)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (max);
}

int
	ft_get_min(t_blist *stack)
{
	int			i;
	const int	n = ft_blstsize(stack);
	int			min;

	i = 0;
	min = *(int *)stack->content;
	while (i < n)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (min);
}

int
	ft_get_max_index(t_blist *stack)
{
	int			i;
	const int	n = ft_blstsize(stack);
	int			max_int;
	int			max;

	i = 0;
	max = *(int *)stack->content;
	max_int = i;
	while (i < n)
	{
		if (*(int *)stack->content > max)
		{
			max_int = i;
			max = *(int *)stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (max_int);
}

int
	ft_get_min_index(t_blist *stack)
{
	int			i;
	const int	n = ft_blstsize(stack);
	int			min_int;
	int			min;

	i = 0;
	min = *(int *)stack->content;
	min_int = i;
	while (i < n)
	{
		if (*(int *)stack->content < min)
		{
			min_int = i;
			min = *(int *)stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (min_int);
}

int
	ft_get_index(t_blist *stack, int num)
{
	int			i;
	const int	n = ft_blstsize(stack);

	i = 0;
	while (i < n)
	{
		if (*(int *)stack->content == num)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
