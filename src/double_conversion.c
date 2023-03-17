/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_conversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <yzaim@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:32:40 by yzaim         #+#    #+#                 */
/*   Updated: 2023/03/03 17:32:41 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double  find_decimals(char* str)
{
    double  decimals;
    double  decimal_place;

    decimals = 0;
    decimal_place = 1;
    while (*str != '.' && *str)
		str++;
    if (*str == '.')
        str++;
    while (str && *str >= '0' && *str <= '9')
    {
        decimals += (double)(*str - '0') / pow(10, decimal_place);
        str++;
        decimal_place++;
    }
    return (decimals);
}

double  ft_atod(char* str)
{
    int     x;
    double  num;

    x = ft_atoi(str);
    if (x < 0)
        num = (double)ft_atoi(str) - find_decimals(str);
    else
        num = (double)ft_atoi(str) + find_decimals(str);
    return (num);
}