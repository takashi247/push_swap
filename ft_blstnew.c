/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:24:00 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 16:30:13 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_blist
	*ft_blstnew(void *content)
{
	t_blist	*new;

	if (!content)
		return (NULL);
	new = (t_blist *)malloc(sizeof(t_blist));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = new;
	new->next = new;
	return (new);
}
