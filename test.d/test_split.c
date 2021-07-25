#include <stdio.h>
#include "libft.h"

int
	main(int ac, char **av)
{
	char	**split;
	char	**head;
	char	*s;
	char	c;

	if (ac != 3)
		return (1);
	s = "\0\0aaa\0bb";
	c = '\0';
	split = ft_split(s, c);
	if (!split)
		return (1);
	head = split;
	printf("ft_split(s = [%s], c = [%c])\n", s, c);
	while (*split)
		printf("[%s]\n", *split++);
	split = head;
	while (*split)
	{
		free(*split);
		*split = NULL;
		split++;
	}
	free(head);
	head = NULL;
	return (0);
}
