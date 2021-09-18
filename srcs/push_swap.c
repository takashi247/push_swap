/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:28:12 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/16 22:53:47 by tnishina         ###   ########.fr       */
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
	char	*s;

	i = 0;
	while (i < size_of_stack)
	{
		s = av[i];
		if (!ft_isint(s))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void
	show_stack(t_blist *head, int size_of_stack)
{
	int	i;

	i = 0;
	while(i < size_of_stack)
	{
		printf("%d\n", *((int *)(head->content)));
		i++;
		head = head->next;
	}
}

static void
	show_actions(t_list *actions)
{
	while (actions)
	{
		ft_putendl_fd(actions->content, STDIN_FILENO);
		actions = actions->next;
	}
}

int
	main(int ac, char **av)
{
	t_blist		*stack_a;
	t_list		*actions;
	const int	size_of_stack = ac - 1;

	if (!size_of_stack)
		return (EXIT_FAILURE);
	if (!is_valid_input(++av, size_of_stack))
		exit_with_error();
	stack_a = convert_to_blists(av, size_of_stack);
	if (!stack_a)
		return (EXIT_FAILURE);
	show_stack(stack_a, size_of_stack); // for debug
	actions = NULL;
	ft_sort_stack(&stack_a, &actions, size_of_stack);
	show_stack(stack_a, size_of_stack); // for debug
	show_actions(actions);
	ft_lstclear(&actions, NULL);
	actions = NULL;
	ft_blstclear(&stack_a, free);
	stack_a = NULL;
	return (EXIT_SUCCESS);
}
