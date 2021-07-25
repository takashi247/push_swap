#include "libft.h"
#include <stdio.h>

int
	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	printf("s1 = [%s], set = [%s]\n", av[1], av[2]);
	printf("trimmed = [%s]\n", ft_strtrim(av[1], av[2]));
	return (0);
}
