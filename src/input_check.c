/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 19:50:00 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/30 11:41:29 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	if (!*s1 || !*s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}

/* Check if input values are doubles */
int	check_double(char *str)
{
	while (str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (true);
	if (*str == '.')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

/* Accept double values between 2 and -2 */
int	check_limits(char *str)
{
	if (ft_atoi(str) > 2 || ft_atoi(str) < -2)
		return (true);
	return (false);
}

int	check_julia_params(char *str1, char *str2)
{
	if (!check_double(str1) || !check_double(str2))
		return (false);
	else if (check_limits(str1) || check_limits(str2))
		return (false);
	return (true);
}

/* Check input values for each fractal inc. fractal name
and/or additional parameters */
int	check_fractol(int argc, char **argv, t_fractol *frac)
{
	if (argc < 2)
		return (ft_error_msg());
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		frac->name = "Mandelbrot";
	else if (ft_strcmp(argv[1], "Julia") == 0 && argc == 4 \
	&& check_julia_params(argv[2], argv[3]))
		frac->name = "Julia";
	else if (ft_strcmp(argv[1], "BurningShip") == 0 && argc == 2)
		frac->name = "BurningShip";
	else
		return (ft_error_msg());
	return (false);
}
