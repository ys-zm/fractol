/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:31:57 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/03 17:35:05 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_julia_start(t_fractol* frac, char **argv)
{
    if (argv)
    {
        frac->im = ft_atod(argv[3]);
        frac->re = ft_atod(argv[2]);
    }
    frac->iter = 100;
    frac->x_ends.start = -2;
    frac->x_ends.end = 2;
    frac->y_ends.start = 2;
    frac->y_ends.end = -2;
    frac->x = 0;
    frac->y = 0;
    frac->org.re = frac->re;
    frac->org.im = frac->im;
    
}

// the +c is the same for all pixel coordinates
int    julia_equation(t_fractol* frac, double x, double y)
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
        re = (re * re) - (im * im) + frac->re;
        im = 2 * store_re * im + frac->im;
        iter_count++;
    }
    return (iter_count);
}