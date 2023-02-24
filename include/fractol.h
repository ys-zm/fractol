#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include "MLX42/MLX42.h"
# include <stdbool.h>
# include <string.h>

# define ERROR -1

# define WIDTH 600
# define HEIGHT 600


typedef struct s_fractol
{
    char*           name;
    mlx_t*          mlx;
	mlx_image_t*    img;
    int          x;
    int          y;
    int          c;
    int          iter;
}   t_fractol;

//STR UTILS
int	ft_strcmp(const char *s1, const char *s2);

//KEYS AND SCROLL
void    keys(void *param);

//DRAW UTILS
double  pix_to_coord( int pix);
void    draw(t_fractol* frac);
void    draw_mandelbrot(t_fractol* frac);
int     mandelbrot(t_fractol* frac, double c_re, double c_im);

//ERROR
int ft_error_msg(void);
int	check_fractol(int argc, char **argv, t_fractol* frac);

#endif