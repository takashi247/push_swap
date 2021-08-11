#include "libft.h"
#include "stdio.h"

int
	main(int ac, char **av)
{
	char	*res;

	if (ac != 2)
		return (1);
	if (ft_isnumeric(av[1]))
		res = "TRUE";
	else
		res = "FALSE";
	printf("ft_isnumeric(%s) = %s\n", av[1], res);
	return (0);
}
