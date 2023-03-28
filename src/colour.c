/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:22:36 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/28 19:52:09 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_rgba(t_fractol *frac)
{
	frac->colours.r = 2;
	frac->colours.g = 1;
	frac->colours.b = 6;
	frac->colours.a = 255;
}

uint32_t	make_colours(t_fractol *frac, int iter_count)
{
	int	r;
	int	g;
	int	b;

	r = frac->colours.r * iter_count;
	g = frac->colours.g * iter_count;
	b = frac->colours.b * iter_count;
	return (r << 24 | g << 16 | b << 8 | frac->colours.a);
}

void	colour_fractal(t_fractol *frac, int x, int y, int iter_count)
{
	if (iter_count == frac->iter)
		mlx_put_pixel(frac->img, x, y, 0x000000FF);
	else
		mlx_put_pixel(frac->img, x, y, make_colours(frac, iter_count));
}

void	increment_rgba(t_fractol *frac, char c)
{
	if (c == 'r')
		frac->colours.r += 2;
	else if (c == 'g')
		frac->colours.g += 2;
	else if (c == 'b')
		frac->colours.b += 2;
	else if (c == 'a')
		frac->colours.a += 2;
}

void	shift_colours(t_fractol *frac, int key)
{
	if (key == 82)
		frac->colours.r += 2;
	else if (key == 71)
		frac->colours.g += 2;
	else if (key == 66)
		frac->colours.b += 2;
	else if (key == 84)
		frac->colours.b += 2;
}
