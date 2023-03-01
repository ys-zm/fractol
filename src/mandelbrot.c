#include "fractol.h"

//---FORMULA TO TRANSLATE COORDINATE FROM PIXEL
// x coord = min + (x_pix / x_totalpix)(x_max - x_min)
double   pix_to_coord(double max, double min, int pix)
{
    double  coord;
    double  temp;

    if (WIDTH < HEIGHT)
    {
        temp = (double)pix / WIDTH;
        coord = (min) + temp * (max - min);
    }
    else
    {
        temp = (double)pix / HEIGHT;
        coord = (min) + temp * (max - min);
    }
    return (coord);
}


void    set_mandelbrot_start(t_fractol* frac)
{
    frac->iter = 127;
    frac->xmin = -2;
    frac->xmax = 2;
    frac->ymin = -2;
    frac->ymax = 2;
    frac->x = 0;
    frac->y = 0;
}

//---FORMULA FOR MANDELBROT
// f(new_pos) = (zx + zy)(zx + zy) + (cx + cy)
int    equation(t_fractol* frac, double c_re, double c_im)
{
    double  re;
    double  im;
    double  store_re;
    int     iter_count;

    re = c_re;
    im = c_im;
    iter_count = 0;
    while((re * re) + (im * im) <= 4 && iter_count < frac->iter)
    {   
        store_re = re;
        re = (re * re) - (im * im) + c_re;
        im = 2 * store_re * im + c_im;
        iter_count++;
    }
    return (iter_count);
}

void    draw_mandelbrot(t_fractol* frac)
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
            iter_count = equation(frac, re, im);
            colour_fractal(frac, x, y, iter_count);
            x++;
        }
        y++;
    }
}