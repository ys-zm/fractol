/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:27 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/06 16:25:59 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>

# define ERROR -1

//TO DO LIST
//make an extra fractal
//reorganise functions
//adjsut colours
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

typedef struct s_window
{
    int32_t width;
    int32_t height;
}   t_window;

typedef struct s_pixel
{
    double  x;
    double  y;
}   t_pixel;

typedef struct s_fractol
{
    char            *name;
    int             iter;
    mlx_t           *mlx;
	mlx_image_t     *img;
    t_ends          x_ends;
    t_ends          y_ends;
    t_pixel         pix;
    t_coord         curr;
    t_coord         org;
    size_t          flag;
    t_window        win_size;
    
}   t_fractol;

//------------INIT------------//
size_t	init_frac(t_fractol *frac);
void	set_settings(t_fractol *frac, char **argv);

//------------STR UTILS------------//
int	    ft_strcmp(const char *s1, const char *s2);
int     smallest(int x, int y);
int     ft_isdigit(char c);
int	    is_space(char c);
double  ft_atod(char *str);
long    ft_atol(const char *str);
int     ft_atoi(const char *str);

//------------KEYS AND SCROLL HOOKS------------//
void	zoom_scroll(double ydelta, double xdelta, void *param);
void	key_hooks(mlx_key_data_t keydata, void *param);
void    nav_mouse_hooks(void *param);
void    resize_window(int32_t width, int32_t height, void *param);

//------------FRACTAL CALCULATIONS------------//
void    set_mandelbrot_start(t_fractol  *frac);
void    set_julia_start(t_fractol *frac, char **argv);
int     mandelbrot_equation(t_fractol *frac, double x, double y);
int     julia_equation(t_fractol* frac, double x, double y);
void    set_burningship_start(t_fractol *frac);
int     burningship_equation(t_fractol *frac, double x, double y);
void    reset(t_fractol *frac);

//------------DRAW FUNCTIONS------------//
double  pix_to_coord_x(double start, double end, int pix, t_fractol *frac);
double  pix_to_coord_y(double start, double end, int pix, t_fractol *frac);
void    draw(t_fractol  *frac);
void    centre_img(t_fractol *frac);

//------------COLOUR SETTINGS------------//
void    colour_fractal(t_fractol *frac, int x, int y, int iter_count);

//------------ERROR------------//
int     check_fractol(int argc, char **argv, t_fractol *frac);
int     ft_error_msg(void);

#endif