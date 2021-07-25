#include "libft.h"
#include <stdio.h>

int
	main(int ac, char **av)
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	if (ac != 3)
	{
		puts("Error: Please input 2 strings\n");
		return (1);
	}
	printf("av[1] = %s, av[2] = %s\n", av[1], av[2]);
	printf("Joined string = %s\n", ft_strjoin(av[1], av[2]));
	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("Joined string = %s\n", ft_strjoin(s1, s1));
	return (0);
}
