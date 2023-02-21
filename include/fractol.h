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
    size_t          x;
    size_t          y;
    size_t          c;
    size_t          iter;
}   t_fractol;

//STR UTILS
ssize_t	ft_strcmp(const char *s1, const char *s2);

//KEYS AND SCROLL
void    keys(void *param);

//DRAW UTILS
size_t  pix_to_coord( size_t pix);
void    draw(t_fractol* frac);
void    draw_mandelbrot(t_fractol* frac);
size_t  mandelbrot(t_fractol* frac, size_t ca, size_t cb);

//ERROR
ssize_t ft_error_msg(void);
size_t	check_fractol(int argc, char **argv, t_fractol* frac);

#endif