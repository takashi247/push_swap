#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("String value = %s, double value = %.400lf\n", av[1], ft_atof(av[1]));
	printf("String value = DOUBLE_MAX, double value = %.400lf\n", DBL_MAX);
	printf("String value = DOUBLE_MIN, double value = %.400lf\n", DBL_MIN);
	printf("String value = DOUBLE_MAX * 1, double value = %.400lf\n", DBL_MAX * 10);
	printf("String value = DOUBLE_MIN / 10, double value = %.400lf\n", DBL_MIN / 10);
	return(0);
}
