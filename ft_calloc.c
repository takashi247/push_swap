/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:27 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:27 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	ptr_size;

	ptr_size = count * size;
	ptr = malloc(ptr_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, ptr_size);
	return (ptr);
}
