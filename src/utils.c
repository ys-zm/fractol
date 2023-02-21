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

ssize_t	ft_strcmp(const char *s1, const char *s2)
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

ssize_t    ft_error_msg(void)
{
    ft_putstr("Wrong input.");
    ft_putstr("Usage: ./fractol <fractol-name>.");
    ft_putstr("Fractol names: Mandelbrot || Julia xx.xx xx.xx");
    return (ERROR);
}

// void    colour_all(t_fractol* frac)
// {
//     size_t  i;
//     size_t  r;

//     i = 0;
//     while (i < HEIGHT)
//     {
//         r = 0;
//         while(r < WIDTH)
//         {
//             mlx_put_pixel(frac->img, r, i, 0xFF0000FF);
//             r++;
//         }
//         i++;
//     }
// }

void    draw(t_fractol* frac)
{
    if (ft_strcmp(frac->name, "Mandelbrot"))
        draw_mandelbrot(frac);
    else
        return ;
}