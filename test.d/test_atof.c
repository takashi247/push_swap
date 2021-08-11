#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("atof:\t\tString value = %s, double value = %.400lf\n", av[1], atof(av[1]));
	printf("ft_atof:\tString value = %s, double value = %.400lf\n", av[1], ft_atof(av[1]));
	// printf("atof:\t\tString value = DOUBLE_MAX, double value = %.400lf\n", DBL_MAX);
	// printf("ft_atof:\tString value = DOUBLE_MAX, double value = %.400lf\n", DBL_MAX);
	// printf("atof:\t\tString value = DOUBLE_MIN, double value = %.400lf\n", DBL_MIN);
	// printf("ft_atof:\tString value = DOUBLE_MIN, double value = %.400lf\n", DBL_MIN);
	// printf("atof:\t\tString value = DOUBLE_MAX * 1, double value = %.400lf\n", DBL_MAX * 10);
	// printf("ft_atof:\tString value = DOUBLE_MAX * 1, double value = %.400lf\n", DBL_MAX * 10);
	// printf("atof:\t\tString value = DOUBLE_MIN / 10, double value = %.400lf\n", DBL_MIN / 10);
	// printf("ft_atof:\tString value = DOUBLE_MIN / 10, double value = %.400lf\n", DBL_MIN / 10);
	// printf("atof:\t\tString value = 1.99e100, double value = %.400lf\n", 1.99e100);
	// printf("ft_atof:\tString value = 1.99e100, double value = %.400lf\n", 1.99e100);
	// printf("atof:\t\tString value = 1.99e-323, double value = %.400lf\n", 1.99e-323);
	// printf("ft_atof:\tString value = 1.99e-323, double value = %.400lf\n", 1.99e-323);
	// printf("atof:\t\tString value = 1.99e-324, double value = %.400lf\n", 1.99e-324);
	// printf("ft_atof:\tString value = 1.99e-324, double value = %.400lf\n", 1.99e-324);
	// printf("atof:\t\tString value = 1.99e10000, double value = %.400lf\n", 1.99e10000);
	// printf("ft_atof:\tString value = 1.99e10000, double value = %.400lf\n", 1.99e10000);
	// printf("atof:\t\tString value = 1.99e10000000000000000000000, double value = %.400lf\n", 1.99e10000000000000000000000);
	// printf("ft_atof:\tString value = 1.99e10000000000000000000000, double value = %.400lf\n", 1.99e10000000000000000000000);
	// printf("atof:\t\tString value = 1.99e1, double value = %.400lf\n", 1.99e1);
	// printf("ft_atof:\tString value = 1.99e1, double value = %.400lf\n", 1.99e1);
	return(0);
}
