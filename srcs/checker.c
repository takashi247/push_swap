/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:26:12 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/10 12:46:11 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_valid_instruction(const char *instruction)
{
	if (!ft_strncmp(instruction, "sa", 3)
		|| !ft_strncmp(instruction, "sb", 3)
		|| !ft_strncmp(instruction, "ss", 3)
		|| !ft_strncmp(instruction, "pa", 3)
		|| !ft_strncmp(instruction, "pb", 3)
		|| !ft_strncmp(instruction, "ra", 3)
		|| !ft_strncmp(instruction, "rb", 3)
		|| !ft_strncmp(instruction, "rr", 3)
		|| !ft_strncmp(instruction, "rra", 4)
		|| !ft_strncmp(instruction, "rrb", 4)
		|| !ft_strncmp(instruction, "rrr", 4))
		return (TRUE);
	else
		return (FALSE);
}

static t_bool
	execute_instruction(t_blist **a, t_blist **b)
{
	int		res;
	char	*instruction;

	while (1)
	{
		res = get_next_line(STDIN_FILENO, &instruction);
		if (res == 1 && is_valid_instruction(instruction))
			ft_do_instruction(a, b, instruction);
		else if (res == 0)
		{
			ft_safe_free(&instruction);
			break ;
		}
		else
		{
			ft_putstr_fd(ERR_MSG, STDERR_FILENO);
			get_next_line(STDIN_FILENO, NULL);
			ft_safe_free(&instruction);
			return (FALSE);
		}
		ft_safe_free(&instruction);
	}
	return (TRUE);
}

int
	main(int ac, char **av)
{
	t_blist	*a;
	t_blist	*b;
	int		size;

	size = ac - 1;
	if (!size)
		return (EXIT_FAILURE);
	if (!ft_is_valid_input(++av, size))
		ft_exit_with_error();
	a = ft_convert_to_blists(av, size);
	if (!a)
		return (EXIT_FAILURE);
	ft_convert_to_index(a, size);
	b = NULL;
	if (execute_instruction(&a, &b))
		ft_is_fully_sorted(a, b);
	ft_blstclear(&a, free);
	ft_blstclear(&b, free);
	a = NULL;
	b = NULL;
	return (EXIT_SUCCESS);
}
