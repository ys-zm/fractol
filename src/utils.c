#include "fractol.h"

size_t  ft_strlen(char *str)
{
    size_t  count;

    count = 0;
    while (str && str[count])
        count++;
    return (count);
}

void    ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

int    ft_error_msg(void)
{
    ft_putstr("Wrong input.");
    ft_putstr("Usage: ./fractol <fractol-name>.");
    ft_putstr("Fractol names: Mandelbrot || Julia xx.xx xx.xx");
    return (ERROR);
}

    static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\v' || c == '\f');
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
    if (*str == '0')
        str++;
    if (*str == '.')
        str++;
	while (*str >= '0' && *str <= '9')
	{
		x = (x * 10) + (*str - '0');
		str++;
	}
    if (*str == '.')
        str++;
    while (*str >= '0' && *str <= '9')
	{
		x = (x * 10) + (*str - '0');
		str++;
	}
	return (x * sign);
}

double  ft_atod(char *str)
{
    int     x;
    int     deci;
    double  num;

    deci = 0;
    x = ft_atoi(str);
    while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
        str++;
    while (str &&  *str >= '0' && *str <= '9')
        str++;
    if (*str == '.')
        str++;
    while (str &&  *str >= '0' && *str <= '9')
    {
        str++;
        deci++;
    }
    printf("x: %d\n", x);
    num = (double)x / pow(10, deci);
    return (num);
}