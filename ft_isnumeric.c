/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:27 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:27 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	check_condition(char c, int has_period, int has_e)
{
	return (c && (ft_isdigit(c) || (c == '.' && !has_period)
			|| ((c == 'e' || c == 'E') && !has_e)));
}

static void
	init_flags(int *has_period, int *has_e)
{
	*has_period = 0;
	*has_e = 0;
}

static int
	validate_index(char **str)
{
	if (*(*str + 1) == '+' || *(*str + 1) == '-')
		(*str)++;
	if (!ft_isdigit(*(*str + 1)))
		return (0);
	else
		return (1);
}

int
	ft_isnumeric(char *str)
{
	int	has_period;
	int	has_e;

	init_flags(&has_period, &has_e);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str) && *str != '.')
		return (0);
	while (check_condition(*str, has_period, has_e))
	{
		if (*str == '.')
		{
			if (!ft_isdigit(*(str + 1)))
				return (0);
			has_period = 1;
		}
		else if (*str == 'e' || *str == 'E')
		{
			if (!validate_index(&str))
				return (0);
			has_e = 1;
		}
		str++;
	}
	return (!*str);
}
