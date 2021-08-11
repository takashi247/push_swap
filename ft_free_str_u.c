#include "libft.h"

void
	ft_free_str_u(unsigned char **us)
{
	free(*us);
	*us = NULL;
}
