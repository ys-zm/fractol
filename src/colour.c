#include "fractol.h"

void    set_colour(t_fractol* frac)
{
    frac->rgba.r = 1;
    frac->rgba.g = 3;
    frac->rgba.b = 6;
    frac->rgba.a = 255;
}

uint32_t    make_colours(int iter_count)
{
    int r = 1 * iter_count;
    int g = 3 * iter_count;
    int b = 6 * iter_count;
    int a = 255;

    return (r << 24 | g << 16 | b << 8 | a);
}

void    colour_fractal(t_fractol* frac, int x, int y, int iter_count)
{
   // set_colour(frac);
    if (iter_count == frac->iter)
        mlx_put_pixel(frac->img, x, y, 0x000000FF);
    else
        mlx_put_pixel(frac->img, x, y, make_colours(iter_count));
}