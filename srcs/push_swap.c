/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:28:12 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:28:58 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	exit_with_error(void)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int
	*convert_to_nums(char **av, const int size_of_stack)
{
	int	i;
	int	*nums;

	if (!av || !size_of_stack)
		return (NULL);
	nums = (int *)malloc(sizeof(int) * size_of_stack);
	if (!nums)
		return (NULL);
	i = 0;
	while (i < size_of_stack)
	{
		nums[i] = atoi(av[i]);
		i++;
	}
	return (nums);
}

static t_bool
	is_valid_input(char **av, const int size_of_stack)
{
	int		i;
	int		zero_flag;
	char	*s;

	i = 0;
	while (i < size_of_stack)
	{
		s = av[i];
		zero_flag = 0;
		if (*s == '+' || *s == '-' || *s == '0')
		{
			if (*s == '0')
				zero_flag = 1;
			s++;
		}
		while (*s && ft_isdigit(*s) && !(zero_flag && *s == '0'))
			s++;
		if (*s)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int
	main(int ac, char **av)
{
	int			*nums;
	int			i;
	const int	size_of_stack = ac - 1;

	if (!size_of_stack)
		return (EXIT_FAILURE);
	if (!is_valid_input(++av, size_of_stack))
		exit_with_error();
	nums = convert_to_nums(av, size_of_stack);
	if (!nums)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size_of_stack)
		printf("%d\n", nums[i++]);
	free(nums);
	nums = NULL;
	return (EXIT_SUCCESS);
}
