#include "fractol.h"

int32_t	main(int argc, char **argv)
{
	t_fractol	frac;
	
	if (check_fractol(argc, argv, &frac))
		return (ERROR);
	set_settings(&frac, argv);
	init_frac(&frac);
	mlx_key_hook(frac.mlx, &key_hooks, &frac);
	mlx_loop_hook(frac.mlx, &nav_mouse_hooks, &frac);
	mlx_scroll_hook(frac.mlx, &zoom_scroll, &frac);	
	//mlx_mouse_hook(frac.mlx, &mouse)
	mlx_loop(frac.mlx);
	mlx_terminate(frac.mlx);
	return (0);
}