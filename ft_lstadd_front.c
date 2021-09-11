/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:28 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:28 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = *lst;
			*lst = new;
			new->next = tmp;
		}
	}
}
