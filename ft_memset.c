/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:28 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:28 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*unsigned_b;
	unsigned char	unsigned_c;

	unsigned_b = (unsigned char *)b;
	unsigned_c = (unsigned char)c;
	while (len)
	{
		*unsigned_b++ = unsigned_c;
		len--;
	}
	return (b);
}
