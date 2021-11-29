/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:28:12 by tnishina          #+#    #+#             */
/*   Updated: 2021/11/28 14:30:59 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	show_actions(t_list *actions)
{
	while (actions)
	{
		ft_putendl_fd(actions->content, STDOUT_FILENO);
		actions = actions->next;
	}
}

int
	main(int ac, char **av)
{
	t_blist		*stack_a;
	t_blist		*stack_b;
	t_ps		ps;

	ft_bzero(&ps, sizeof(ps));
	ps.all_size = ac - 1;
	ps.sub_size = ps.all_size;
	if (!ps.all_size)
		return (EXIT_FAILURE);
	if (!ft_is_valid_input(++av, ps.all_size))
		ft_exit_with_error();
	stack_a = ft_convert_to_blists(av, ps.all_size);
	if (!stack_a)
		return (EXIT_FAILURE);
	ft_convert_to_index(stack_a, ps.all_size);
	stack_b = NULL;
	ft_sort_stack(&stack_a, &stack_b, &ps, TRUE);
	show_actions(ps.actions);
	ft_lstclear(&(ps.actions), NULL);
	ps.actions = NULL;
	ps.batch_size_lst = NULL;
	ft_blstclear(&stack_a, free);
	stack_a = NULL;
	stack_b = NULL;
	return (EXIT_SUCCESS);
}
