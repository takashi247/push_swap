#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int
	main(int ac, char **av)
{
	char	c = av[1][0];

	printf("Original: %c\n", c);
	printf("tolower: %c\n", tolower(c));
	printf("ft_tolower: %c\n", ft_tolower(c));
	return (0);
}
