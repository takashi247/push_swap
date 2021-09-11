/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:29 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:29 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char
	*ft_strdup_u(const unsigned char *us1)
{
	unsigned char	*dup;
	unsigned char	*head;
	size_t			len;

	if (!us1)
		return (NULL);
	len = ft_strlen_u(us1);
	dup = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (!dup)
		return (NULL);
	head = dup;
	while (*us1)
		*dup++ = *us1++;
	*dup = '\0';
	return (head);
}
