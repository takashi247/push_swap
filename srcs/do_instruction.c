/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:26:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/10 12:43:27 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	do_reverse_instruction(t_blist **a, t_blist **b, const char *instruction)
{
	if (!ft_strncmp(instruction, "ra", 3))
		*a = (*a)->next;
	else if (!ft_strncmp(instruction, "rb", 3))
		*b = (*b)->next;
	else if (!ft_strncmp(instruction, "rr", 3))
	{
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (!ft_strncmp(instruction, "rra", 4))
		*a = (*a)->prev;
	else if (!ft_strncmp(instruction, "rrb", 4))
		*b = (*b)->prev;
	else
	{
		*a = (*a)->prev;
		*b = (*b)->prev;
	}
}

void
	ft_do_instruction(t_blist **a, t_blist **b, const char *instruction)
{
	if (!ft_strncmp(instruction, "r", 1))
		do_reverse_instruction(a, b, instruction);
	else if (!ft_strncmp(instruction, "sa", 3))
		ft_swap_stack(a);
	else if (!ft_strncmp(instruction, "sb", 3))
		ft_swap_stack(b);
	else if (!ft_strncmp(instruction, "ss", 3))
	{
		ft_swap_stack(a);
		ft_swap_stack(b);
	}
	else if (!ft_strncmp(instruction, "pa", 3))
		ft_push_stack(b, a);
	else
		ft_push_stack(a, b);
}
