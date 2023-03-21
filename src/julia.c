/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:31:57 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/21 15:50:08 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Default settings for Julia
//Only set width and height if it is the start setting
void    set_julia_start(t_fractol* frac, char **argv, int if_start_set)
{
    if (argv)
    {
        frac->curr.re = ft_atod(argv[2]);
        frac->curr.im = ft_atod(argv[3]);
    }
    if (if_start_set)
    {
        frac->win_size.width = 1080;
        frac->win_size.height = 700;
    }
    frac->iter = 100;
    frac->x_ends.start = -2;
    frac->x_ends.end = 2;
    frac->y_ends.start = 2;
    frac->y_ends.end = -2;
    frac->pix.x = 0;
    frac->pix.y = 0;
    frac->org.re = frac->curr.re;
    frac->org.im = frac->curr.im;
    frac->flag = 0;
    centre_img(frac);
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
        re = (re * re) - (im * im) + frac->curr.re;
        im = 2 * store_re * im + frac->curr.im;
        iter_count++;
    }
    return (iter_count);
}