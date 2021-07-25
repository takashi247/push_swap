#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int
	main(void)
{
	char	c = 'A';

	printf("Original: %c\n", c);
	printf("toupper: %c\n", toupper(c));
	printf("ft_toupper: %c\n", ft_toupper(c));
	return (0);
}
