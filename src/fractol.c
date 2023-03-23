/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:33:08 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/23 19:34:01 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_calls(t_fractol *frac)
{
	mlx_key_hook(frac->mlx, &key_hooks, frac);
	mlx_loop_hook(frac->mlx, &nav_mouse_hooks, frac);
	mlx_scroll_hook(frac->mlx, &zoom_scroll, frac);
	mlx_resize_hook(frac->mlx, &resize_window, frac);
}

int32_t	main(int argc, char **argv)
{
	t_fractol	frac;

	if (check_fractol(argc, argv, &frac))
		return (ERROR);
	set_settings(&frac, argv);
	init_frac(&frac);
	hook_calls(&frac);
	mlx_loop(frac.mlx);
	mlx_terminate(frac.mlx);
	return (0);
}
