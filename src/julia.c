#include "fractol.h"

void    set_julia_start(t_fractol* frac, char **argv)
{
    frac->iter = 127;
    frac->xmin = -2;
    frac->xmax = 2;
    frac->ymin = -2;
    frac->ymax = 2;
    frac->x = 0;
    frac->y = 0;
    frac->im = ft_atod(argv[3]);
    frac->re = ft_atod(argv[2]);
}

// the +c is the same for all pixel coordinates
int    julia_equation(t_fractol* frac, double x, double y)
{
    double  re;
    double  im;
    double  store_re;
    int     iter_count;

    iter_count = 0;
    re = x;
    im = y;
    while((re * re) + (im * im) <= 4 && iter_count < frac->iter)
    {   
        store_re = re;
        re = (re * re) - (im * im) + frac->re;
        im = 2 * store_re * im + frac->im;
        iter_count++;
    }
    return (iter_count);
}

void    draw_julia(t_fractol* frac)
{
    int  x;
    int  y;
    double  re;
    double  im;
    int  iter_count;

    y = 0;
    while ( y < HEIGHT)
    {
        x = 0;
        im = pix_to_coord(frac->ymax, frac->ymin, y) + frac->y;
        while (x < WIDTH)
        {
            re = pix_to_coord(frac->xmax, frac->xmin, x) + frac->x;
            iter_count = julia_equation(frac, re, im);
            colour_fractal(frac, x, y, iter_count); 
            x++;
        }
        y++;
    }
}