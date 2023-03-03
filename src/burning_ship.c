#include "fractol.h"

void    set_burningship_start(t_fractol *frac)
{
    frac->iter = 100;
    frac->x_ends.start = -2;
    frac->x_ends.end = 2;
    frac->y_ends.start = 2;
    frac->y_ends.end = -2;
    frac->x = 0;
    frac->y = 0;
}

int burningship_equation(t_fractol *)
{
    
}