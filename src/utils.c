/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:02 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/23 19:46:25 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	smallest(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	reset(t_fractol *frac)
{
	set_mandelbrot_start(frac, 0);
	set_julia_start(frac, NULL, 0);
	draw(frac);
}
