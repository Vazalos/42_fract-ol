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

void ft_nova(int x, int y, t_data *mlx)
{
    int     i;
    double  z_tmp;
    int     color;
    double  z_cubed;
    double  z_squared;

    i = 0;
    mlx->z.xr = 1;
    mlx->z.yi = 0;
    mlx->c.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
    mlx->c.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
    while (++i <= mlx->max_iter)
    {
        z_squared = ft_squared(mlx->z.xr) + ft_squared(mlx->z.yi); // z^2
        z_cubed = (mlx->z.xr * z_squared) - (3 * mlx->z.xr * ft_squared(mlx->z.yi)) + 
                  (3 * mlx->z.xr * ft_squared(mlx->z.yi)) - (mlx->z.yi * z_squared); // z^3
        z_tmp = mlx->z.xr - ((z_cubed - 1) / (3 * z_squared)) + mlx->c.xr;
        mlx->z.yi = mlx->z.yi - ((3 * mlx->z.xr * ft_squared(mlx->z.yi) - z_squared + 1) / (3 * z_squared)) + mlx->c.yi;
        mlx->z.xr = z_tmp;

        if (z_squared > 1)
        {
            color = ft_color_profile(i, mlx);
            ft_put_pixel(mlx, x, y, color);
            return ;
        }
    }
    ft_put_pixel(mlx, x, y, BLACK);
}

