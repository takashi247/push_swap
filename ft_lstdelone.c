/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:28 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:28 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && (*del))
	{
		(*del)(lst->content);
		lst->content = NULL;
		free(lst);
		lst = NULL;
	}
}
