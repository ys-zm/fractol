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

//check the input is valid
int	check_fractol(int argc, char **argv, t_fractol* frac)
{
	if (argc < 2)
		return (ft_error_msg());
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		frac->name = "Mandelbrot";
	else if (ft_strcmp(argv[1], "Julia") == 0 && argc == 4)
		frac->name = "Julia";
	else
		return (ft_error_msg());
	return (0);
}

int    ft_error_msg(void)
{
    ft_putstr("Wrong input.");
    ft_putstr("Usage: ./fractol <fractol-name>.");
    ft_putstr("Fractol names: Mandelbrot || Julia xx.xx xx.xx");
    return (ERROR);
}