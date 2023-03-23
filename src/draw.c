/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:12 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/23 19:19:53 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pix_to_coord_x(double start, double end, int pix, t_fractol *frac)
{
	double	coord;
	double	interval;

	interval = (end - start) / frac->win_size.width;
	coord = start + interval * (double)pix;
	return (coord);
}

double	pix_to_coord_y(double start, double end, int pix, t_fractol *frac)
{
	double	coord;
	double	interval;

	interval = (start - end) / frac->win_size.height;
	coord = start - interval * (double)pix;
	return (coord);
}

int	choose_equation(t_fractol *frac, double re, double im)
{
	int	iter_count;

	iter_count = 0;
	if (ft_strcmp(frac->name, "Mandelbrot") == 0)
		iter_count = mandelbrot_equation(frac, re, im);
	else if (ft_strcmp(frac->name, "Julia") == 0)
		iter_count = julia_equation(frac, re, im);
	else
		iter_count = burningship_equation(frac, re, im);
	return (iter_count);
}

void	draw(t_fractol *frac)
{
	double	re;
	double	im;
	int		x;
	int		y;
	int		iter_count;

	y = 0;
	while (y < frac->win_size.height)
	{
		x = 0;
		im = pix_to_coord_y(frac->y_ends.start, frac->y_ends.end, y, frac);
		im += frac->pix.y;
		while (x < frac->win_size.width)
		{
			re = pix_to_coord_x(frac->x_ends.start, frac->x_ends.end, x, frac);
			re += frac->pix.x;
			iter_count = choose_equation(frac, re, im);
			colour_fractal(frac, x, y, iter_count);
			x++;
		}
		y++;
	}
}
