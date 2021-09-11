/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:29 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:29 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcpy_u(unsigned char *dst, const unsigned char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	if (!src)
		return (0);
	len_src = ft_strlen_u(src);
	if (!dst || !dstsize)
		return (len_src);
	i = 0;
	while (i < len_src && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
