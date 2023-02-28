#include "fractol.h"

//check the input is valid
int	check_fractol(int argc, char **argv, t_fractol* frac)
{
	if (argc < 2)
		return (ft_error_msg());
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		frac->name = "Mandelbrot";
	else if (ft_strcmp(argv[1], "Julia") == 0 && argc == 4)
		frac->name = "Julia";
	else
		return (ft_error_msg());
	return (0);
}

size_t	init_frac(t_fractol* frac)
{
	frac->mlx = mlx_init(WIDTH, HEIGHT, frac->name, true);
	if (!(frac->mlx))
		return (ERROR);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!(frac->img))
		return (ERROR);
	// set_mandelbrot_start(frac);
	// draw_mandelbrot(frac);
	julia(frac);
	return (0);
	
}
int32_t	main(int argc, char **argv)
{
	t_fractol	frac;
	
	if (check_fractol(argc, argv, &frac))
		return (ERROR);
	set_julia_start(&frac, argv);
	init_frac(&frac);
	//mlx_loop_hook(frac.mlx, &mouse, &frac);
	mlx_loop_hook(frac.mlx, &keys, &frac);
	mlx_scroll_hook(frac.mlx, &scroll, &frac);
	mlx_image_to_window(frac.mlx, frac.img, 0, 0);
	mlx_loop(frac.mlx);
	return (0);
}

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_t* mlx;
// 	mlx_image_t* img;
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
// 	if (!mlx)
// 		ft_error();
// 	/* Do stuff */
// 	// Create and display the image.
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();
// 	mlx_put_pixel(img, 300, 300, 0xFF0000FF);
// 	mlx_loop_hook(mlx, &esp, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }