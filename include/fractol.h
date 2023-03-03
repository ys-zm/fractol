/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:27 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/03 17:37:52 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include "MLX42/MLX42.h"
# include <stdbool.h>
# include <string.h>
# include <math.h>

# define ERROR -1
# define WIDTH 1080
# define HEIGHT 800

//make it a union
typedef struct s_ends
{
    double  start;
    double  end;
}   t_ends;

union rgba
{
    int r;
    int g;
    int b;
    int a;
};

typedef struct s_coord
{
    double  re;
    double  im;
}   t_coord;

typedef struct s_fractol
{
    char*           name;
    mlx_t*          mlx;
	mlx_image_t*    img;
    int             iter;
    double          x;
    double          y;
    t_ends          x_ends;
    t_ends          y_ends;
    double          im;
    double          re;
    t_coord         org;
}   t_fractol;

//INIT
size_t	init_frac(t_fractol* frac);
void	set_settings(t_fractol* frac, char **argv);

//STR UTILS
int	    ft_strcmp(const char *s1, const char *s2);
double  ft_atod(char *str);
int	    is_space(char c);
int     ft_isdigit(char c);
int     smallest(int x, int y);

//KEYS AND SCROLL HOOKS
void    nav_mouse_hooks(void *param);
void	zoom_scroll(double ydelta, double xdelta, void *param);
void	key_hooks(mlx_key_data_t keydata, void *param);

//CALCULATE FRACTAL
double  pix_to_coord_x(double start, double end, int pix);
double  pix_to_coord_y(double start, double end, int pix);
void    set_mandelbrot_start(t_fractol* frac);
void    set_julia_start(t_fractol* frac, char **argv);
int     mandelbrot_equation(t_fractol* frac, double x, double y);
int     julia_equation(t_fractol* frac, double x, double y);
void    reset(t_fractol *frac);

void    draw(t_fractol* frac);

//COLOUR
void    colour_fractal(t_fractol* frac, int x, int y, int iter_count);

//ERROR
int     check_fractol(int argc, char **argv, t_fractol* frac);
int     ft_error_msg(void);

#endif