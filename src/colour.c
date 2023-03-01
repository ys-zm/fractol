#include "fractol.h"

void    colour_fractal(t_fractol* frac, int x, int y, int iter_count)
{
    if (iter_count == frac->iter)
        mlx_put_pixel(frac->img, x, y, 0x000000FF);
    else
    {
        // iter_count = iter_count<<24;
        // iter_count *= 15;
        mlx_put_pixel(frac->img, x, y, 0xFFFFFFFF * iter_count);
    }
}