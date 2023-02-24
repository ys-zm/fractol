#include "fractol.h"

//---FORMULA TO TRANSLATE COORDINATE FROM PIXEL
// x coord = x_min + (x_pix / x_totalpix)(x_max - x_min)
double   pix_to_coord(t_fractol* frac, int pix)
{
    double  coord;
    double  temp;

    temp = (double)pix / HEIGHT;
    coord = (frac->min) + temp * (frac->max - frac->min);
    return (coord);
}


void    set_mandelbrot_start(t_fractol* frac)
{
    frac->iter = 100;
    frac->min = -2;
    frac->max = 2;
    frac->x = 0;
    frac->y = 0;
    frac->zoom = 1;
}

//---FORMULA FOR MANDELBROT
// f(new_pos) = (zx + zy)(zx + zy) + (cx + cy)
int    mandelbrot(t_fractol* frac, double c_re, double c_im)
{
    double  re;
    double  im;
    double  store_re;
    int  iter_count;

    re = 0;
    im = 0;
    iter_count = 0;
    while((re * re) + (im * im) < 4 && iter_count < frac->iter)
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
        while (x < WIDTH)
        {
            re = pix_to_coord(frac, x) + frac->x;
            // printf("re: %f", re);
            im = pix_to_coord(frac, y) + frac->y;
            // printf("im: %f", im);
            iter_count = mandelbrot(frac, re, im);
            //printf("itercount: %d\n", iter_count);
            // printf("min: %f", frac->min);
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