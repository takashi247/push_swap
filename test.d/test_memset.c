#include "libft.h"
#include <string.h>
#include <stdio.h>

int
	main(int ac, char** av)
{
	char str[50];

	strcpy(str,"This is string.h library function");
	puts(str);

	ft_memset(str,'$',7);
	puts(str);

	return(0);
}