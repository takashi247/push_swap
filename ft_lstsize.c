/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:28 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:28 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_lstsize(t_list *lst)
{
	int	len_lst;

	if (!lst)
		return (0);
	len_lst = 0;
	while (lst)
	{
		len_lst++;
		lst = lst->next;
	}
	return (len_lst);
}
