/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 08:54:36 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 09:24:08 by tnishina         ###   ########.fr       */
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

/*
** To run quick sort
**
** 1. Determine the pivot
**
**  [10] [12] [15] [3] [8] [17] [4] [1]
**                      p
**
** 2. Swap the pivot with the one in the right edge and start i, j from the left
**
**                      *----swap----*
**  [10] [12] [15] [3] [1] [17] [4] [8]
**   i,j                             p
**
** 3. Increment j if num[j] >= pivot
**
**  [10] [12] [15] [3] [1] [17] [4] [8]
**   i -----------> j                p
**
** 4. Swap num[i] and num[j] and increment i if num[j] < pivot
**
**   *----swap-----*
**  [3] [12] [15] [10] [1] [17] [4] [8]
**   --> i         j                 p
**
** 5. Again, increment j if num[j] >= pivot
**
**  [3] [12] [15] [10] [1] [17] [4] [8]
**       i          --> j            p
**
** 6. Repeat 4. if num[j] < pivot
**
**       *-----swap----*
**  [3] [1] [15] [10] [12] [17] [4] [8]
**       --> i         j             p
**
** 7. Again, increment j if num[j] >= pivot
**
**  [3] [1] [15] [10] [12] [17] [4] [8]
**           i          -------> j   p
**
** 8. Repeat 4. if num[j] < pivot
**
**           *-------swap-------*
**  [3] [1] [4] [10] [12] [17] [15] [8]
**           --> i              j    p
**
** 9. Swap i and the pivot when j reaches to the next to the pivot
**
**               *-------swap-------*
**  [3] [1] [4] [8] [12] [17] [15] [10]
**               i             j    p
**
** 10. Run the same steps recursively with the left-hand side of the pivot
**     (those which are lower than the pivot) and th right-hand side of the
**     pivot (those which are larger than or equal to the pivot) respectively
**     (when the size of the array is 1, just return)
**
**   --small--       -------big-------
**  [3] [1] [4] [8] [12] [17] [15] [10]
**               p
*/

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

/*
** Convert numbers given by command line arguments into index numbers starting
** from 0 to size_of_stack - 1
*/

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
