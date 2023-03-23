/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:31:53 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/23 19:45:41 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in_x(t_fractol	*frac, double re, int x)
{
	double	range;
	double	new_range;
	double	cut_off;
	double	prop;

	range = frac->x_ends.end - frac->x_ends.start;
	cut_off = range * 0.2;
	new_range = range - cut_off;
	prop = (double)x / frac->win_size.width;
	frac->x_ends.start = re - prop * new_range;
	frac->x_ends.end = frac->x_ends.start + new_range;
}

static void	zoom_in_y(t_fractol *frac, double im, int y)
{
	double	range;
	double	cut_off;
	double	new_range;
	double	prop;

	range = frac->y_ends.start - frac->y_ends.end;
	cut_off = range * 0.2;
	new_range = range - cut_off;
	prop = (double)y / frac->win_size.height;
	frac->y_ends.start = im + (prop * new_range);
	frac->y_ends.end = frac->y_ends.start - new_range;
}

static void	zoom_out_y(t_fractol *frac, double im, int y)
{
	double	range;
	double	new_range;
	double	add_on;
	double	prop;

	range = frac->y_ends.start - frac->y_ends.end;
	add_on = range * 0.2;
	new_range = range + add_on;
	prop = (double)y / frac->win_size.height;
	frac->y_ends.start = im + (prop * new_range);
	frac->y_ends.end = frac->y_ends.start - new_range;
}

static void	zoom_out_x(t_fractol *frac, double re, int x)
{
	double	range;
	double	new_range;
	double	add_on;
	double	prop;

	range = frac->x_ends.end - frac->x_ends.start;
	add_on = range * 0.2;
	new_range = range + add_on;
	prop = (double)x / frac->win_size.width;
	frac->x_ends.start = re - prop * new_range;
	frac->x_ends.end = frac->x_ends.start + new_range;
}

void	zoom_scroll(double ydelta, double xdelta, void *param)
{
	t_fractol	*frac;
	int32_t		x;
	int32_t		y;
	double		y_coord;
	double		x_coord;

	frac = param;
	mlx_get_mouse_pos(frac->mlx, &x, &y);
	(void)ydelta;
	y_coord = pix_to_coord_y(frac->y_ends.start, frac->y_ends.end, y, frac);
	x_coord = pix_to_coord_x(frac->x_ends.start, frac->x_ends.end, x, frac);
	if (xdelta < 0)
	{
		zoom_in_x(frac, x_coord, x);
		zoom_in_y(frac, y_coord, y);
		draw(frac);
	}
	else
	{
		zoom_out_x(frac, x_coord, x);
		zoom_out_y(frac, y_coord, y);
		draw(frac);
	}
}
