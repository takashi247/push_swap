#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int
	main(int ac, char **av)
{
	char	*heystack;
	char	*needle;
	int		len;

	if (ac != 4)
		return (1);
	heystack = av[1];
	needle = av[2];
	len = atoi(av[3]);
	printf("strnstr(%s, %s, %d)\n", heystack, needle, len);
	printf("%s\n", strnstr(heystack, needle, len));
	printf("ft_strnstr(%s, %s, %d)\n", heystack, needle, len);
	printf("%s\n", ft_strnstr(heystack, needle, len));
	return (0);
}
