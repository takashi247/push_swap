/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:28:12 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/03 15:46:42 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	exit_with_error(void)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static t_blist
	*convert_to_blists(char **av, const int size_of_stack)
{
	int		i;
	t_blist	*head;
	t_blist	*new;
	int		*num;

	if (!av || !size_of_stack)
		return (NULL);
	i = 0;
	head = NULL;
	while (i < size_of_stack)
	{
		num = (int *)malloc(sizeof(int));
		if (num)
			*num = ft_atoi_s(av[i]);
		new = ft_blstnew(num);
		if (!new)
		{
			ft_blstclear(&head, free);
			return (NULL);
		}
		ft_blstadd_back(&head, new);
		i++;
	}
	return (head);
}

static t_bool
	is_valid_input(char **av, const int size_of_stack)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (i < size_of_stack)
	{
		s = av[i];
		if (!ft_isint(s))
			return (FALSE);
		j = 0;
		while (j < i)
		{
			if (!ft_strncmp(av[i], av[j], ft_strlen(av[i]) + 1))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void
	ft_show_actions(t_list *actions)
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
	if (!is_valid_input(++av, ps.all_size))
		exit_with_error();
	stack_a = convert_to_blists(av, ps.all_size);
	if (!stack_a)
		return (EXIT_FAILURE);
	ft_convert_to_index(stack_a, ps.all_size);
	stack_b = NULL;
	ft_sort_stack(&stack_a, &stack_b, &ps, TRUE);
	ft_show_actions(ps.actions);
	ft_lstclear(&(ps.actions), NULL);
	ps.actions = NULL;
	ps.p_sizes = NULL;
	ft_blstclear(&stack_a, free);
	stack_a = NULL;
	stack_b = NULL;
	return (EXIT_SUCCESS);
}
