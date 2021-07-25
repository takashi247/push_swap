#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(int ac, char **av)
{
	char	dst1[10] = "abcd";
	char	dst2[10] = "abcd";
	char	*src;
	size_t	size;
	size_t	ret;

	if (ac != 3)
		return (1);
	src = av[1];
	size = (size_t)atoi(av[2]);
	ret = strlcat(dst1, src, size);
	printf("<Result of strlcat(dst1[10] = \"%s\", %s, %zu)>\ndst: %s, ret: %zu\n", dst1, src, size, dst1, ret);
	ret = ft_strlcat(dst2, src, size);
	printf("<Result of ft_strlcat(dst2[10] = \"%s\", %s, %zu)>\ndst: %s, ret: %zu\n", dst2, src, size, dst2, ret);
	return (0);
}
