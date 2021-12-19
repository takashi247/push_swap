/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:55:40 by tnishina          #+#    #+#             */
/*   Updated: 2021/12/19 15:39:25 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_exit_with_error(void)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_blist
	*ft_convert_to_blists(char **av, const int size_of_stack)
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

t_bool
	ft_is_valid_input(char **av, const int size_of_stack)
{
	int		i;
	int		j;
	int		current;
	int		old;
	char	*s;

	i = 0;
	while (i < size_of_stack)
	{
		s = av[i];
		if (!ft_isint(s))
			return (FALSE);
		j = 0;
		current = ft_atoi_s(s);
		while (j < i)
		{
			old = ft_atoi_s(av[j]);
			if (current == old)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
