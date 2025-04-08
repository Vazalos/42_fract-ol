/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:43:17 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/11 14:44:26 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_mandelbrot(int x, int y, t_data *mlx)
{
	int			i;
	double		z_tmp;
	int			color;

	i = 0;
	mlx->z.xr = 0;	
	mlx->z.yi = 0;
	mlx->c.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
	mlx->c.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
	while (++i <= mlx->max_iter)
	{
		z_tmp = ft_squared(mlx->z.xr) - ft_squared(mlx->z.yi) + mlx->c.xr;
		mlx->z.yi = (2 * mlx->z.xr * mlx->z.yi) + mlx->c.yi;
		mlx->z.xr = z_tmp;
		if (ft_squared(mlx->z.xr) + ft_squared(mlx->z.yi) > mlx->escape_val)
		{
			color = ft_color_profile(i, mlx);
			ft_put_pixel(mlx, x, y, color);
			return ;
		}
	}
	ft_put_pixel(mlx, x, y, BLACK);
}

void ft_julia(int x, int y, t_data *mlx) 
{
    int			i;
    double		z_tmp;
    int			color;

    i = 0;
	mlx->c.xr = mlx->julia.xr;
	mlx->c.yi = mlx->julia.yi;
    mlx->z.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
    mlx->z.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
    while (++i <= mlx->max_iter)
	{
        z_tmp = ft_squared(mlx->z.xr) - ft_squared(mlx->z.yi) + mlx->c.xr;
        mlx->z.yi = 2 * mlx->z.xr * mlx->z.yi + mlx->c.yi;
        mlx->z.xr = z_tmp;
        if (ft_squared(mlx->z.xr) + ft_squared(mlx->z.yi) > mlx->escape_val) {
            color = ft_color_profile(i, mlx);
            ft_put_pixel(mlx, x, y, color);
            return ;
        }
    }
    ft_put_pixel(mlx, x, y, BLACK);
}

t_complex sin_squared_plus_c(t_complex z, t_complex c) {
    // Calculate sin(z)
    t_complex sin_z;
	t_complex sin_z_squared;
	t_complex result;

	sin_z.xr = sin(z.xr) * cosh(z.yi);
	sin_z.yi = cos(z.xr) * sinh(z.yi);
	sin_z_squared.xr = ft_squared(sin_z.xr) - ft_squared(sin_z.yi);
	sin_z_squared.yi = (sin_z.xr * sin_z.yi) + (sin_z.xr * sin_z.yi);
	result.xr = sin_z_squared.xr + c.xr;
	result.yi = sin_z_squared.yi + c.yi;
    
    return result;
}

void	ft_sin(int x, int y, t_data *mlx)
{
	int			i;
	int			color;
	t_complex	result;

	i = 0;

	if(mlx->toggle == 0)
	{
	mlx->z.xr = 0;	
	mlx->z.yi = 0;
	mlx->c.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
	mlx->c.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
	}
	if(mlx->toggle == 1)
	{
		mlx->c.xr = mlx->julia.xr;
		mlx->c.yi = mlx->julia.yi;
		mlx->z.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->z.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
	}
	while (++i <= mlx->max_iter)
	{
		result = sin_squared_plus_c(mlx->z, mlx->c);
		mlx->z.xr = result.xr;
		mlx->z.yi = result.yi;
		if (ft_squared(mlx->z.xr) + ft_squared(mlx->z.yi) > 100)
		{
			color = ft_color_profile(i, mlx);
			ft_put_pixel(mlx, x, y, color);
			return ;
		}
	}
	ft_put_pixel(mlx, x, y, BLACK);
}
