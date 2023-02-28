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

# define WIDTH 600
# define HEIGHT 600


typedef struct s_fractol
{
    char*           name;
    mlx_t*          mlx;
	mlx_image_t*    img;
    int             iter;
    double             x;
    double             y;
    double          xmin;
    double          xmax;
    double          ymin;
    double          ymax;
    double          scroll;
}   t_fractol;

//STR UTILS
int	ft_strcmp(const char *s1, const char *s2);
double  ft_atod(char *str);

//KEYS AND SCROLL
void    keys(void *param);
void	scroll(double ydelta, double xdelta, void *param);

//DRAW UTILS
double   pix_to_coord(double max, double min, int pix);
void    draw(t_fractol* frac);
void    draw_mandelbrot(t_fractol* frac);
int     equation(t_fractol* frac, double c_re, double c_im);
void    set_mandelbrot_start(t_fractol* frac);
void    julia(t_fractol* frac);
void    set_julia_start(t_fractol* frac, char **argv);

//ERROR
int ft_error_msg(void);
int	check_fractol(int argc, char **argv, t_fractol* frac);

#endif