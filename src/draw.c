/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:12 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/03 17:33:43 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  pix_to_coord_x(double start, double end, int pix)
{
    double  coord;
    double  interval;

    interval = (end - start) / HEIGHT; 
    coord = start + interval * (double)pix;
    return (coord);
}

double pix_to_coord_y(double start, double end, int pix)
{
    double  coord;
    double  interval;

    interval = (start - end) / HEIGHT;
    coord = start - interval * (double)pix;
    return (coord);
}

int choose_equation(t_fractol *frac, double re, double im)
{
    int iter_count;

    iter_count = 0;
    if (ft_strcmp(frac->name, "Mandelbrot") == 0)
        iter_count = mandelbrot_equation(frac, re, im);
    else
        iter_count = julia_equation(frac, re, im);
    return (iter_count);
}

void    draw(t_fractol* frac)
{
    int     x;
    int     y;
    double  re;
    double  im;
    int     iter_count;

    y = 0;
    while ( y < HEIGHT)
    {
        x = 0;
        im = pix_to_coord_y(frac->y_ends.start, frac->y_ends.end, y) + frac->y;
        while (x < WIDTH)
        {
            re = pix_to_coord_x(frac->x_ends.start, frac->x_ends.end, x) + frac->x;
            iter_count = choose_equation(frac, re, im);
            colour_fractal(frac, x, y, iter_count); 
            x++;
        }
        y++;
    }
}
