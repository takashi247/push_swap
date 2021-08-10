#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("LONG_MIN: %ld\n", LONG_MIN);
	printf("DOUBLE_MAX: %g\n", DBL_MAX);
	printf("DOUBLE_MIN: %g\n", DBL_MIN);
	printf("atoi: String value = %s, Int value = %d\n", av[1], atoi(av[1]));
	printf("ft_atoi: String value = %s, Int value = %d\n", av[1], ft_atoi(av[1]));
	printf("ft_atoi_s: String value = %s, Int value = %d\n", av[1], ft_atoi_s(av[1]));
	return(0);
}
