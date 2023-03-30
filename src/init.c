/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:46:46 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/30 11:40:16 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Calls for initial settings */
void	set_settings(t_fractol *frac, char **argv)
{
	if (ft_strcmp(frac->name, "Mandelbrot") == 0)
		set_mandelbrot_start(frac, 1);
	else if (ft_strcmp(frac->name, "Julia") == 0)
		set_julia_start(frac, argv, 1);
	else
		set_burningship_start(frac, 1);
}

/* Initialize window and image */
size_t	init_frac(t_fractol *frac)
{
	frac->mlx = mlx_init(frac->win_size.width, \
	frac->win_size.height, frac->name, true);
	if (!(frac->mlx))
		return (ERROR);
	frac->img = mlx_new_image(frac->mlx, frac->win_size.width, \
	frac->win_size.height);
	if (!(frac->img))
		return (ERROR);
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	return (0);
}
