/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 20:02:56 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/02 20:02:57 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void keys(void *param)
{
    t_fractol	*frac;

	frac = param;
	if (mlx_is_key_down(frac->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(frac->mlx);
		mlx_terminate(frac->mlx);
	}
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_RIGHT))
		frac->x += (frac->xmax - frac->xmin) * 0.1;
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_LEFT))
		frac->x -= (frac->xmax - frac->xmin) * 0.1;
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_UP))
		frac->y -= (frac->ymax - frac->ymin) * 0.1;
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_DOWN))
		frac->y += (frac->ymax - frac->ymin) * 0.1;
	draw(frac);
}

static void	zoom_in_x(t_fractol	*frac, double re, int x)
{
	double range;
	double	new_range;
	double cut_off;
	double	prop;

	range = frac->xmax - frac->xmin; //4
	cut_off = range * 0.2; //0.8
	new_range = range - cut_off; //3.2
	prop = (double)x / WIDTH; //0.25
	printf("propx: %f\n", prop);
	frac->xmin = re - prop * new_range; // -1 - (0.25 * 3.2) = -1.8
	frac->xmax = frac->xmin + new_range; // -1.8 + 3.2 = 1.4
}


static void	zoom_in_y(t_fractol *frac, double im, int y)
{
	double	range;
	double	cut_off;
	double	new_range;
	double	prop;

	range = frac->ymin - frac->ymax; //4
	cut_off = range * 0.2; //0.8
	new_range = range - cut_off; //3.2
	prop = (double)y / HEIGHT; 
	printf("propy: %f\n", prop);
	frac->ymin = im + (prop * new_range); 
	frac->ymax = frac->ymin - new_range; 
}

// static void	zoom_out_y(t_fractol *frac, double im)
// {
// 	double	range;
// 	double	new_range;
// 	double	add_on;
// 	double	prop;

// 	range = frac->ymax - frac->ymin;
// 	add_on = range * 0.2;
// 	new_range = range + add_on;
// 	prop = (range - frac->ymin - im) / range;
// 	frac->ymax = im + (prop * new_range);
// 	frac->ymin = frac->ymax - new_range;
// }

// static void	zoom_out_x(t_fractol *frac, double re)
// {
// 	double range;
// 	double	new_range;
// 	double add_on;
// 	double	prop;

// 	range = frac->xmax - frac->xmin;
// 	add_on = range * 0.2;
// 	new_range = range + add_on;
// 	prop = (range - frac->xmin + re) / range; 
// 	frac->xmin = re - (prop * new_range);
// 	frac->xmax = frac->xmin + new_range;
// }

void	scroll(double ydelta, double xdelta, void* param)
{
	t_fractol	*frac;
	int32_t		x;
	int32_t		y;
	double		y_coord;
	double		x_coord;

	frac = param;
	mlx_get_mouse_pos(frac->mlx, &x, &y);
	(void)ydelta;
	y_coord = pix_to_coord(frac->ymax, frac->ymin, y);
	printf("y coord: %f\n", y_coord);
	x_coord = pix_to_coord(frac->xmax, frac->xmin, x);
	printf("x coord: %f\n", x_coord);
	if (xdelta < 0)
	{
		zoom_in_x(frac, x_coord, x);
		zoom_in_y(frac, y_coord, y);
	}
	// else
	// {
	// 	zoom_out_x(frac, x_coord);
	// 	zoom_out_y(frac, y_coord);
	// }
	draw(frac);
}
