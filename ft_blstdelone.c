/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:05:51 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 17:04:56 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_blstdelone(t_blist *blst, void (*del)(void *))
{
	if (blst)
	{
		if (*del)
			(*del)(blst->content);
		blst->content = NULL;
		free(blst);
	}
}
