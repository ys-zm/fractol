#include "fractol.h"

//---FORMULA TO TRANSLATE COORDINATE FROM PIXEL
// x coord = x_min + (x_pix / x_totalpix)(x_max - x_min)
size_t    pix_to_coord( size_t pix)
{
    ssize_t  coord;
    ssize_t  min = -2;
    ssize_t  max = 2;

    coord = (min) + (pix / HEIGHT) * (max - min);
    return (coord);
}

//---FORMULA FOR MANDELBROT
// f(new_pos) = (zx + zy)(zx + zy) + (cx + cy)
//i have a problem here!
size_t    mandelbrot(t_fractol* frac, size_t ca, size_t cb)
{
    ssize_t  a;
    ssize_t  b;
    size_t  store_a;
    size_t  iter_count;

    a = 0;
    b = 0;
    iter_count = 0;
    frac->iter = 50;
    while(iter_count < 50)
    {   
        store_a = a;
        a = (a * a) - (b * b) + ca;
        b = 2 * store_a * b + cb;
        iter_count++;

    }
    return (iter_count);
}

void    draw_mandelbrot(t_fractol* frac)
{
    size_t  x;
    size_t  y;
    ssize_t  a;
    ssize_t  b;
    size_t  iter_count;

    y = 0;
    while ( y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            a = pix_to_coord(x);
            printf("a: %zd", a);
            b = pix_to_coord(y);
            printf("b: %zd", b);
            iter_count = mandelbrot(frac, a, b);
            printf("itercount: %zd\n", iter_count);
            if (iter_count == frac->iter)
                mlx_put_pixel(frac->img, x, y, 0xFF0000FF);
            else
                mlx_put_pixel(frac->img, x, y, 0xFFFF00FF);
            x++;
        }
        printf("%zd, x; %zd, y;", x, y);
        y++;
    }
    mlx_image_to_window(frac->mlx, frac->img, 0, 0);
}