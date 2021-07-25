#include "libft.h"
#include <stdio.h>

int
	main(int ac, char **av)
{
	int	n;

	if (ac != 2)
		return (1);
	n = ft_atoi(av[1]);
	ft_putstr_fd("ft_putnbr_fd\n", STDOUT_FILENO);
	ft_putnbr_fd(n, STDOUT_FILENO);
	return (0);
}
