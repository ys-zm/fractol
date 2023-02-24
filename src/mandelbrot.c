#include "fractol.h"

//---FORMULA TO TRANSLATE COORDINATE FROM PIXEL
// x coord = x_min + (x_pix / x_totalpix)(x_max - x_min)
double   pix_to_coord(int pix)
{
    double  coord;
    double  temp;
    double  min = -2;
    double  max = 2;

    temp = (double)pix / HEIGHT;
    coord = (min) + temp * (max - min);
    return (coord);
}

//---FORMULA FOR MANDELBROT
// f(new_pos) = (zx + zy)(zx + zy) + (cx + cy)
//i have a problem here!
int    mandelbrot(t_fractol* frac, double c_re, double c_im)
{
    double  re;
    double  im;
    double  store_re;
    int  iter_count;

    re = 0;
    im = 0;
    iter_count = 0;
    frac->iter = 50;
    while((re * re) + (im * im) < 4 && iter_count < 50)
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
            re = pix_to_coord(x);
            printf("re: %f", re);
            im = pix_to_coord(y);
            printf("im: %f", im);
            iter_count = mandelbrot(frac, re, im);
            printf("itercount: %d\n", iter_count);
            if (iter_count == frac->iter)
                mlx_put_pixel(frac->img, x, y, 0xFF0000FF);
            else
                mlx_put_pixel(frac->img, x, y, 0x008080FF * iter_count);
            x++;
        }
        printf("%d, x; %d, y;", x, y);
        y++;
    }
    mlx_image_to_window(frac->mlx, frac->img, 0, 0);
}