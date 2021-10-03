/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:54:36 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 09:46:16 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	find_index(int n, int *nums, int size_of_stack)
{
	int	i;

	i = 0;
	while (i < size_of_stack)
	{
		if (nums[i] == n)
			return (i);
		i++;
	}
	return (i);
}

static void
	swap_nums(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void
	num_qsort(int *nums, int left, int right)
{
	int	pivot_index;
	int	pivot;
	int	i;
	int	j;

	if (right - left <= 1)
		return ;
	pivot_index = (left + right) / 2;
	pivot = nums[pivot_index];
	swap_nums(nums + pivot_index, nums + right - 1);
	i = left;
	j = left;
	while (j < right - 1)
	{
		if (nums[j] < pivot)
			swap_nums(nums + i++, nums + j);
		j++;
	}
	swap_nums(nums + i, nums + right - 1);
	num_qsort(nums, left, i);
	num_qsort(nums, i + 1, right);
}

void
	ft_convert_to_index(t_blist *a, const int size_of_stack)
{
	int	*nums;
	int	i;
	int	index;

	nums = (int *)malloc(sizeof(int) * size_of_stack);
	if (!nums)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size_of_stack)
	{
		nums[i++] = *(int *)a->content;
		a = a->next;
	}
	num_qsort(nums, 0, size_of_stack);
	i = 0;
	while (i < size_of_stack)
	{
		index = find_index(*(int *)a->content, nums, size_of_stack);
		if (index == size_of_stack)
			exit(EXIT_FAILURE);
		*(int *)a->content = index;
		i++;
		a = a->next;
	}
	free(nums);
}
