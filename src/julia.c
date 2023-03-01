#include "fractol.h"

void    set_julia_start(t_fractol* frac, char **argv)
{
    frac->iter = 127;
    frac->xmin = -2;
    frac->xmax = 2;
    frac->ymin = -2;
    frac->ymax = 2;
    frac->x = ft_atod(argv[2]);
    frac->y = ft_atod(argv[3]);
}

void    draw_julia(t_fractol* frac)
{
    int  x;
    int  y;
    double  re;
    double  im;
    int  iter_count;

    printf("%f\n", frac->y);
     //printf("%f\n", frac->x);
    y = 0;
    while ( y < HEIGHT)
    {
        x = 0;
        im = pix_to_coord(frac->ymax, frac->ymin, y) + frac->y;
        while (x < WIDTH)
        {
            re = pix_to_coord(frac->xmax, frac->xmin, x) + frac->x;
            iter_count = equation(frac, re, im);
            colour_fractal(frac, x, y, iter_count); 
            x++;
        }
        y++;
    }
}