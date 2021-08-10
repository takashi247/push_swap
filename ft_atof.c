#include "libft.h"

static long double
	get_denominator(int i)
{
	long double	denominator;
	int			count;

	denominator = 1;
	count = 0;
	while (count++ < i)
		denominator /= 10;
	return (denominator);
}

double
	ft_atof(const char *str)
{
	long double	ld_num;
	int			sign;
	int			i;

	ld_num = 0.0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		ld_num = ld_num * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	i = 1;
	while (ft_isdigit(*str))
		ld_num += (*str++ - '0') * get_denominator(i++);
	return ((double)(sign * ld_num));
}
