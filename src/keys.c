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
	{
		frac->x += 0.02;
		draw_mandelbrot(frac);
	}
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_LEFT))
	{
		frac->x -= 0.02;
		draw_mandelbrot(frac);
	}
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_UP))
	{
		frac->y -= 0.02;
		draw_mandelbrot(frac);
	}
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_DOWN))
	{
		frac->y += 0.02;
		draw_mandelbrot(frac);
	}
}

void	scroll(double ydelta, double xdelta, void* param)
{
	t_fractol*	frac;

	frac = param;
	(void)ydelta;
	if (xdelta < 0)
	{
		frac->max *= 0.8;
		frac->min *= 0.8;
		frac->zoom *= 1.5;
	}
	else if (xdelta > 0)
	{
		frac->min *= 1.2;
		frac->max *= 1.2;
		frac->zoom *= 0.9;
	}
	draw_mandelbrot(frac);
}
