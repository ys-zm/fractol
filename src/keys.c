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
	//else if (mlx_is_key_down(mlx, MLX_KEY_UP))
}
