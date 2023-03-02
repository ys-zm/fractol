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

static int	ft_atoi(const char *str)
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

static double  find_decimals(char* str)
{
    double  decimals;
    double  decimal_place;

    decimals = 0;
    decimal_place = 1;
    while (*str != '.')
		str++;
    str++;
    while (str && *str >= '0' && *str <= '9')
    {
        decimals += (double)(*str - '0') / pow(10, decimal_place);
        str++;
        decimal_place++;
    }
    return (decimals);
}

double  ft_atod(char* str)
{
    int     x;
    double  num;

    x = ft_atoi(str);
    if (x < 0)
        num = (double)ft_atoi(str) - find_decimals(str);
    else
        num = (double)ft_atoi(str) + find_decimals(str);
    return (num);
}