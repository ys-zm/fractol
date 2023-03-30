/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:22:36 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/30 11:46:49 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Start colour settings for fractals */
void	set_rgba(t_fractol *frac)
{
	frac->colours.r = 2;
	frac->colours.g = 1;
	frac->colours.b = 6;
	frac->colours.a = 255;
}

/* RGB values are based on how many iterations it take for a
coordinate to escape a circle of radius 2 */
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

/* Points s that remain at max_iter are black
The colour of the rest depend in the iter_count */
void	colour_fractal(t_fractol *frac, int x, int y, int iter_count)
{
	if (iter_count == frac->iter)
		mlx_put_pixel(frac->img, x, y, 0x000000FF);
	else
		mlx_put_pixel(frac->img, x, y, make_colours(frac, iter_count));
}

/* Function to edit colour scheme to be more red, 
green, blue or change transparency */
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

/* 82 == R KEY | 71 == G KEY | 66 == B KEY | 84 == T KEY */
void	shift_colours(t_fractol *frac, int key)
{
	if (key == 82)
		frac->colours.r += 2;
	else if (key == 71)
		frac->colours.g += 2;
	else if (key == 66)
		frac->colours.b += 2;
	else if (key == 84)
		frac->colours.a += 2;
}
