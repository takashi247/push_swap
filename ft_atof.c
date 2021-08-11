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

static long double
	get_index(const char *str)
{
	long double	index;
	double		multiplier;
	int			count;

	index = 1.0;
	str++;
	multiplier = 10.0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			multiplier = 0.1;
		str++;
	}
	count = ft_atoi_s(str);
	if (!count && ft_isdigit(*str) && *str != '0')
	{
		if (multiplier == 10.0)
			return (INFINITY);
		else
			count = MAX_NEGATIVE_INDEX;
	}
	while (count--)
		index *= multiplier;
	return ((double)index);
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
	if (*str == 'e')
		return ((double)(sign * ld_num * get_index(str)));
	else
		return ((double)(sign * ld_num));
}
