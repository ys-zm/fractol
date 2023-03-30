/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:07 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/30 11:48:53 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Default settings for Mandelbrot
Only set width and height if it is the start setting */
void	set_mandelbrot_start(t_fractol *frac, int if_start_set)
{
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
	frac->flag = 0;
	frac->org.im = 0;
	frac->org.re = 0;
	frac->curr.im = 0;
	frac->curr.re = 0;
	set_rgba(frac);
	centre_img(frac);
}

/* Equation for Mandelbrot set: F(X) = Z^2 + C
 Becomes: F(X) = (ZX + ZY)^2 + (CX + CY) 
 The C value is the original position of the point */
int	mandelbrot_equation(t_fractol *frac, double x, double y)
{
	int		iter_count;
	double	store_re;
	double	re;
	double	im;

	re = x;
	im = y;
	iter_count = 0;
	while ((re * re) + (im * im) <= 4 && iter_count < frac->iter)
	{
		store_re = re;
		re = (re * re) - (im * im) + x;
		im = 2 * store_re * im + y;
		iter_count++;
	}
	return (iter_count);
}
