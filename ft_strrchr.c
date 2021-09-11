/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:30 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:30 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	len_s;

	if (!s)
		return (NULL);
	ch = (char)c;
	len_s = ft_strlen(s);
	while (1)
	{
		if (s[len_s] == ch)
			return ((char *)(s + len_s));
		if (len_s)
			len_s--;
		else
			return (NULL);
	}
}
