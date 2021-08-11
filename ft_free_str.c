#include "libft.h"

void
	ft_free_str(char **s)
{
	free(*s);
	*s = NULL;
}
