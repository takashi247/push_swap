/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:29 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:29 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char
	*ft_strjoin_u(unsigned char const *us1, unsigned char const *us2)
{
	size_t			len;
	unsigned char	*us_joined;

	if (!us1 && !us2)
		return (NULL);
	else if (!us1)
		return (ft_strdup_u(us2));
	else if (!us2)
		return (ft_strdup_u(us1));
	len = ft_strlen_u(us1) + ft_strlen_u(us2);
	us_joined = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (!us_joined)
		return (NULL);
	ft_strlcpy_u(us_joined, us1, len + 1);
	ft_strlcat_u(us_joined, us2, len + 1);
	return (us_joined);
}
