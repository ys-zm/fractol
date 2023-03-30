/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:27:40 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/30 11:49:48 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Function to centralize the fractal in the window 
depending on width & height */
void	centre_img(t_fractol *frac)
{
	double	range_y;
	double	range_x;

	if (frac->win_size.width > frac->win_size.height)
	{
		range_y = frac->y_ends.start - frac->y_ends.end;
		range_x = (range_y / frac->win_size.height) * frac->win_size.width;
		frac->x_ends.start = -(range_x / 2);
		frac->x_ends.end = range_x / 2;
		frac->y_ends.start = range_y / 2;
		frac->y_ends.end = -(range_y / 2);
	}
	else if (frac->win_size.width < frac->win_size.height)
	{
		range_x = frac->x_ends.end - frac->x_ends.start;
		range_y = (range_x / frac->win_size.width) * frac->win_size.height;
		frac->y_ends.start = range_y / 2;
		frac->y_ends.end = -(range_y / 2);
		frac->x_ends.start = -(range_x / 2);
		frac->x_ends.end = range_x / 2;
	}
}

/* Function to resize the window */
void	resize_window(int32_t width, int32_t height, void *param)
{
	t_fractol	*frac;

	frac = param;
	if (width != frac->win_size.width || height != frac->win_size.height)
	{
		frac->win_size.width = width;
		frac->win_size.height = height;
		mlx_resize_image(frac->img, frac->win_size.width, \
		frac->win_size.height);
		centre_img(frac);
	}
}
