#include "libft.h"

static int
	check_condition(char c, int has_period, int has_e)
{
	return (c && (ft_isdigit(c) || (c == '.' && !has_period)
			|| (c == 'e' && !has_e)));
}

static void
	init_flags(int *has_period, int *has_e)
{
	*has_period = 0;
	*has_e = 0;
}

int
	ft_isnumeric(char *str)
{
	int	has_period;
	int	has_e;

	init_flags(&has_period, &has_e);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str) && *str != '.')
		return (0);
	while (check_condition(*str, has_period, has_e))
	{
		if (*str == '.')
		{
			if (!ft_isdigit(*(str + 1)))
				return (0);
			has_period = 1;
		}
		else if (*str == 'e')
		{
			if (!ft_isdigit(*(str + 1)))
				return (0);
			has_e = 1;
		}
		str++;
	}
	return (!*str);
}
