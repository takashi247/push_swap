/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:30 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:30 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_substr;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= (size_t)start)
		return (ft_strdup("\0"));
	if (len_s - (size_t)start < len)
		len_substr = len_s - (size_t)start;
	else
		len_substr = len;
	substr = (char *)malloc(sizeof(char) * (len_substr + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len_substr)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
