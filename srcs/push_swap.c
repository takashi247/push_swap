/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:28:12 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 17:02:46 by tnishina         ###   ########.fr       */
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

int
	main(int ac, char **av)
{
	t_blist		*head;
	t_blist		*current;
	int			i;
	const int	size_of_stack = ac - 1;

	if (!size_of_stack)
		return (EXIT_FAILURE);
	if (!is_valid_input(++av, size_of_stack))
		exit_with_error();
	head = convert_to_blists(av, size_of_stack);
	if (!head)
		return (EXIT_FAILURE);
	i = 0;
	current = head;
	while (i < size_of_stack)
	{
		printf("%d\n", *((int *)(current->content)));
		i++;
		current = current->next;
	}
	ft_blstclear(&head, free);
	head = NULL;
	return (EXIT_SUCCESS);
}
