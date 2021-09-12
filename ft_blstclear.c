/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:10:14 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 15:10:15 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_blstclear(t_blist **blst, void (*del)(void *))
{
	t_blist	*current;
	t_blist	*tmp;

	if (blst && (*del))
	{
		current = *blst;
		while (current)
		{
			tmp = current->next;
			ft_blstdelone(current, del);
			current = tmp;
		}
		*blst = NULL;
	}
}
