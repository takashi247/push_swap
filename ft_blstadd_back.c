/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:02:21 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 15:02:23 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_blstadd_back(t_blist **blst, t_blist *new)
{
	t_blist	*last;

	if (blst && new)
	{
		if (*blst == NULL)
			*blst = new;
		else
		{
			last = (*blst)->prev;
			new->prev = last;
			last->next = new;
			new->next = *blst;
			(*blst)->prev = new;
		}
	}
}
