/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:23:48 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/10 11:24:26 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_is_fully_sorted(t_blist *a, t_blist *b)
{
	if (ft_is_sorted(a) && !ft_blstsize(b))
		ft_putstr_fd(OK_MSG, STDOUT_FILENO);
	else
		ft_putstr_fd(KO_MSG, STDOUT_FILENO);
}

void
	ft_safe_free(char **str)
{
	free(*str);
	*str = NULL;
}
