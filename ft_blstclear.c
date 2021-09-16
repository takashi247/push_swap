/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:10:14 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/16 22:48:35 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_blstclear(t_blist **blst, void (*del)(void *))
{
	t_blist	*current;
	t_blist	*tmp;
	int		i;
	int		n;

	if (blst)
	{
		i = 0;
		n = ft_blstsize(*blst);
		current = *blst;
		while (i < n)
		{
			tmp = current->next;
			ft_blstdelone(current, del);
			current = tmp;
			i++;
		}
		*blst = NULL;
	}
}
