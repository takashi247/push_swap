#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%d\n", __INT_MAX__);
	printf("%ld\n", __LONG_MAX__);
	printf("atoi: String value = %s, Int value = %d\n", av[1], atoi(av[1]));
	printf("ft_atoi: String value = %s, Int value = %d\n", av[1], ft_atoi(av[1]));
	printf("ft_atoi_s: String value = %s, Int value = %d\n", av[1], ft_atoi_s(av[1]));
	return(0);
}
