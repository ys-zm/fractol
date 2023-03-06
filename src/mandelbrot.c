/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:07 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/06 15:51:50 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_mandelbrot_start(t_fractol *frac)
{
    frac->iter = 100;
    frac->x_ends.start = -2;
    frac->x_ends.end = 2;
    frac->y_ends.start = 2;
    frac->y_ends.end = -2;
    frac->pix.x = 0;
    frac->pix.y = 0;
    frac->win_size.width = 1080;
    frac->win_size.height = 700;
    frac->flag = 0;
    frac->org.im = 0;
    frac->org.re = 0;
    frac->curr.im = 0;
    frac->curr.re = 0;
    centre_img(frac);
}

//---FORMULA FOR MANDELBROT
// f(new_pos) = (zx + zy)(zx + zy) + (cx + cy)
int mandelbrot_equation(t_fractol *frac, double x, double y)
{
    int     iter_count;
    double  store_re;
    double  re;
    double  im;

    re = x;
    im = y;
    iter_count = 0;
    while((re * re) + (im * im) <= 4 && iter_count < frac->iter)
    {   
        store_re = re;
        re = (re * re) - (im * im) + x;
        im = 2 * store_re * im + y;
        iter_count++;
    }
    return (iter_count);
}