#include "fractol.h"

void    set_julia_start(t_fractol* frac, char **argv)
{
    frac->iter = 120;
    frac->xmin = -2;
    frac->xmax = 2;
    frac->ymin = -2;
    frac->ymax = 2;
    frac->x = ft_atod(argv[2]);
    frac->y = ft_atod(argv[3]);
}

void    julia(t_fractol* frac)
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
            if (iter_count == frac->iter)
                mlx_put_pixel(frac->img, x, y, 0xFF0000FF);
            else
            {
                iter_count = iter_count<<24;
                iter_count *= 15;
                mlx_put_pixel(frac->img, x, y, 0x008080FF + iter_count);
            }
                
            x++;
        }
        y++;
    }
}