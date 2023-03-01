#include "fractol.h"

void	set_settings(t_fractol* frac, char **argv)
{
	if (ft_strcmp(frac->name, "Mandelbrot") == 0)
		set_mandelbrot_start(frac);
	else if (ft_strcmp(frac->name, "Julia") == 0)
		set_julia_start(frac, argv);
}

size_t	init_frac(t_fractol* frac)
{
	frac->mlx = mlx_init(WIDTH, HEIGHT, frac->name, true);
	if (!(frac->mlx))
		return (ERROR);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!(frac->img))
		return (ERROR);
	draw(frac);
	return (0);
}

int32_t	main(int argc, char **argv)
{
	t_fractol	frac;
	
	if (check_fractol(argc, argv, &frac))
		return (ERROR);
	set_settings(&frac, argv);
	init_frac(&frac);
	//mlx_loop_hook(frac.mlx, &mouse, &frac);
	mlx_loop_hook(frac.mlx, &keys, &frac);
	mlx_scroll_hook(frac.mlx, &scroll, &frac);
	mlx_image_to_window(frac.mlx, frac.img, 0, 0);
	mlx_loop(frac.mlx);
	return (0);
}