/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:43:29 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/11 16:43:29 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putstr_fd_u(unsigned char *us, int fd)
{
	size_t	len_us;

	if (us && 0 <= fd)
	{
		len_us = ft_strlen_u(us);
		write(fd, us, len_us);
	}
}
