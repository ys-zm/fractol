#include "fractol.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\v' || c == '\f');
}

int ft_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		x = (x * 10) + (*str - '0');
		str++;
	}
	return (x * sign);
}