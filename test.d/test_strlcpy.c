#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(int ac, char **av)
{
	char	dst1[10];
	char	dst2[10];
	char	*src;
	size_t	size;
	size_t	ret;

	if (ac != 3)
		return (1);
	src = av[1];
	size = (size_t)atoi(av[2]);
	ret = ft_strlcpy(dst2, src, size);
	printf("<Result of ftstrlcpy(dst2[10], %s, %zu)>\ndst: %s, ret: %zu\n", src, size, dst2, ret);
	printf("Size of dst2: %zu\n", sizeof(dst2));
	ret = strlcpy(dst1, src, size);
	printf("<Result of strlcpy(dst1[10], %s, %zu)>\ndst: %s, ret: %zu\n", src, size, dst1, ret);
	printf("Size of dst1: %zu\n", sizeof(dst1));
	return (0);
}
