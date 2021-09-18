/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:03 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/18 17:16:32 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_blstadd_front(t_blist **blst, t_blist *new)
{
	if (blst && new)
	{
		if (*blst == NULL)
			*blst = new;
		else
		{
			new->prev = (*blst)->prev;
			(*blst)->prev->next = new;
			new->next = (*blst);
			(*blst)->prev = new;
			*blst = new;
		}
	}
}
