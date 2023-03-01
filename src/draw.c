#include "fractol.h"

void draw(t_fractol* frac)
{
    if (ft_strcmp(frac->name, "Mandelbrot") == 0)
        draw_mandelbrot(frac);
    else if (ft_strcmp(frac->name, "Julia") == 0)
        draw_julia(frac);
}