/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:08:30 by tnishina          #+#    #+#             */
/*   Updated: 2021/10/10 11:04:56 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FD 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define GNL_SUCCESS 1
# define GNL_ERROR -1
# define GNL_EOF 0

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(int fd, char **line);

#endif
