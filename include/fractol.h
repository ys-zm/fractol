#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include "MLX42/MLX42.h"
# include <stdbool.h>
# include <string.h>
#include <math.h>

# define ERROR -1

# define WIDTH 1080
# define HEIGHT 720

typedef struct s_rgba
{
    int r;
    int g;
    int b;
    int a;
}   t_rgba;

typedef struct s_fractol
{
    char*           name;
    mlx_t*          mlx;
	mlx_image_t*    img;
    int             iter;
    double          x;
    double          y;
    double          xmin;
    double          xmax;
    double          ymin;
    double          ymax;
    double          scroll;
    double          im;
    double          re;
    t_rgba         rgba; 
}   t_fractol;

//STR UTILS
int	    ft_strcmp(const char *s1, const char *s2);
double  ft_atod(char *str);

//KEYS AND SCROLL
void    keys(void *param);
void	scroll(double ydelta, double xdelta, void *param);

//DRAW UTILS
double  pix_to_coord(double max, double min, int pix);
void    draw(t_fractol* frac);
void    draw_mandelbrot(t_fractol* frac);
int     equation(t_fractol* frac, double c_re, double c_im);
void    set_mandelbrot_start(t_fractol* frac);
void    draw_julia(t_fractol* frac);
void    set_julia_start(t_fractol* frac, char **argv);
void    draw(t_fractol* frac);

//COLOUR
void    colour_fractal(t_fractol* frac, int x, int y, int iter_count);

//ERROR
int     ft_error_msg(void);
int     check_fractol(int argc, char **argv, t_fractol* frac);

#endif