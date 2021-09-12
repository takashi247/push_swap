/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:51:24 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 09:51:26 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool
	is_overflow(long l_num, char c)
{
	if (l_num > INT_MAX / 10
		|| (l_num == INT_MAX / 10 && c - '0' > INT_MAX % 10)
		|| l_num < INT_MIN / 10
		|| (l_num == INT_MIN / 10 && c - '0' > INT_MIN % 10 * -1))
		return (TRUE);
	else
		return (FALSE);
}

/*
** return true if number is within int range
*/

t_bool
	ft_is_int_range(const char *str)
{
	long	l_num;
	int		sign;

	l_num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_overflow(sign * l_num, *str))
			return (FALSE);
		l_num = l_num * 10 + (*str++ - '0');
	}
	return (TRUE);
}
