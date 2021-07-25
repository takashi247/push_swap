#include <stdio.h>
#include <string.h>
#include "libft.h"

int
	main(int ac, char **av)
{
	char	*s;
	int		c;

	if (ac != 3)
		return (1);
	s = av[1];
	c = '\0';
	printf("<strchr test>\n");
	printf("s = %s, c = %c\n", s, c);
	printf("strchr: %s\n", strchr(s, c));
	printf("ft_strchr: %s\n", ft_strchr(s, c));
}
