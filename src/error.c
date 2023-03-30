/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:20:44 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/30 11:37:17 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

static void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/* Error message for invalid input */
int	ft_error_msg(void)
{
	ft_putstr("Wrong input.\n");
	ft_putstr("Usage: ./fractol <fractol-name> <additional-parameters>.\n");
	ft_putstr("Fractol names: Mandelbrot || Julia xx.xx xx.xx || BurningShip\n");
	ft_putstr("Add float values for the Julia set (between 2 and -2).\n");
	return (true);
}
