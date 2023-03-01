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

void	scroll(double ydelta, double xdelta, void* param)
{
	t_fractol*	frac;
	int32_t	x;
	int32_t	y;
	double	y_coord;
	double	x_coord;

	frac = param;
	mlx_get_mouse_pos(frac->mlx, &x, &y);
	(void)ydelta;
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		y_coord = pix_to_coord(frac->ymax, frac->ymin, y);
		x_coord = pix_to_coord(frac->xmax, frac->xmin, x);
		if (xdelta < 0)
		{
			frac->ymax += (frac->ymax - frac->ymin) * 0.1 * (y / HEIGHT);
			frac->ymin -= (frac->ymax - frac->ymin) * 0.1 * (1 - (y / HEIGHT));
			frac->xmax += (frac->xmax - frac->xmin) * 0.1 * (1 - (x / WIDTH));
			frac->xmin -= (frac->xmax - frac->xmin) * 0.1 * (x / WIDTH);
		}
		else if (xdelta > 0)
		{
			frac->ymin += (frac->ymax - frac->ymin) * 0.1 * (1 - (y / HEIGHT));
			frac->ymax -= (frac->ymax - frac->ymin) * 0.1 * (y / HEIGHT);
			frac->xmin += (frac->xmax - frac->xmin) * 0.1 * (x / WIDTH);
			frac->xmax -= (frac->xmax - frac->xmin) * 0.1 * (1 - (x / WIDTH));
		}
	}
	draw_mandelbrot(frac);
}
