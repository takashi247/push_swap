/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:47:09 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 14:59:02 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_blstsize(t_blist *blst)
{
	t_blist	*current;
	int		size;

	current = blst;
	size = 0;
	if (!current)
		return (size);
	size++;
	while (current->next != blst)
	{
		size++;
		current = current->next;
	}
	return (size);
}
