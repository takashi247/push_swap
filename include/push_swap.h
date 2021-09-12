/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:52:32 by tnishina          #+#    #+#             */
/*   Updated: 2021/09/12 09:52:38 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "t_bool.h"

// need to delete
# include <stdio.h>

# define ERR_MSG "Error\n"

typedef struct s_blist
{
	int				num;
	struct s_blist	*prev;
	struct s_blist	*next;
}	t_blist;

/* is_int_range.c */
t_bool		ft_is_int_range(const char *str);

#endif
