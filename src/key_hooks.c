/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 20:02:56 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/23 19:57:39 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	navigate(t_fractol *frac)
{
	if (mlx_is_key_down(frac->mlx, MLX_KEY_RIGHT))
		frac->pix.x += (frac->x_ends.end - frac->x_ends.start) * 0.1;
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_LEFT))
		frac->pix.x -= (frac->x_ends.end - frac->x_ends.start) * 0.1;
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_UP))
		frac->pix.y -= (frac->y_ends.start - frac->y_ends.end) * 0.1;
	else if (mlx_is_key_down(frac->mlx, MLX_KEY_DOWN))
		frac->pix.y += (frac->y_ends.start - frac->y_ends.end) * 0.1;
}

static void	mouse_input(t_fractol *frac)
{
	int32_t		x;
	int32_t		y;
	int			y[2];
	int			x[2];

	if (mlx_is_mouse_down(frac->mlx, MLX_MOUSE_BUTTON_LEFT))
		frac->flag = !(frac->flag);
	if (frac->flag)
	{
		mlx_get_mouse_pos(frac->mlx, &x, &y);
		y[0] = frac->y_ends.start;
		y[1] = frac->y_ends.end;
		x[0] = frac->x_ends.start;
		x[1] = frac->x_ends.end;
		frac->curr.im = pix_to_coord_y(y[0], y[1], y, frac);
		frac->curr.re = pix_to_coord_x(x[0], x[1], x, frac);
		printf("im: %f\n", frac->curr.im);
		printf("re: %f\n", frac->curr.re);
	}
	draw(frac);
}

static void	switch_fracs(t_fractol *frac)
{
	if (ft_strcmp(frac->name, "Mandelbrot") == 0)
		frac->name = "Julia";
	else
		frac->name = "Mandelbrot";
	draw(frac);
}

void	nav_mouse_hooks(void *param)
{
	t_fractol	*frac;

	frac = param;
	navigate(frac);
	mouse_input(frac);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frac;

	frac = param;
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		switch_fracs(frac);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(frac->mlx);
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		frac->iter += 10;
	else if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		frac->iter -= 10;
	else if (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_G \
	|| keydata.key == MLX_KEY_B || keydata.key == MLX_KEY_T)
		shift_colours(frac, keydata.key);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		reset(frac);
}
