#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int
	main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	int		n;

	if (ac != 4)
		return (1);
	s1 = av[1];
	s2 = av[2];
	n = atoi(av[3]);
	printf("strncmp(%s, %s, %d)\n", s1, s2, n);
	printf("result: %d\n", strncmp(s1, s2, n));
	printf("ft_strncmp(%s, %s, %d)\n", s1, s2, n);
	printf("result: %d\n", ft_strncmp(s1, s2, n));
	return (0);
}
