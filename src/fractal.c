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


void	ft_fractal(int x, int y, t_data *mlx)
{
	t_complex	z;
	t_complex	c;
	int		i;
	double		z_tmp;
	int		color;

	i = 0;
	z.xr = 0;
	z.yi = 0;
	c.xr = ft_map(x, mlx->win_xrange, mlx->fract_xrange);
	c.yi = ft_map(y, mlx->win_yrange, mlx->fract_yrange);
	while (++i <= mlx->max_iterations)
	{
		z_tmp = (z.xr * z.xr) - (z.yi * z.yi) + c.xr;
		z.yi = (2 * z.xr * z.yi) + c.yi;
		z.xr = z_tmp;
		if (((z.xr * z.xr) + (z.yi * z.yi)) > mlx->escape_value)
		{
			color = ft_encode_argb(255, ft_map(i, ft_range(0, mlx->escape_value), ft_range(0, 50)), 
										ft_map(i, ft_range(0, mlx->escape_value), ft_range(0, 100)),
										ft_map(i, ft_range(0, mlx->escape_value), ft_range(0, 200)));	
			//color = ft_encode_argb(255, 255*i/42, 255*i/42, 255);
			//color = ft_map(i, mlx->color_range, mlx->color_iter);
			//printf("iter:%d omin:%f omax:%f, nmin:%f nmax:%f ", i, mlx->color_range.min, mlx->color_range.max, mlx->color_iter.min, mlx->color_iter.max);
			//printf("%d\n", color);
			ft_put_pixel(mlx, x, y, color);
			return ;
		}
	}
	ft_put_pixel(mlx, x, y, BLACK);
}
/*
int	ft_draw_fractal(t_data *mlx)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	y = -1;
	color = ft_encode_argb(0, 100, 0, 100);
	while (++y <= HEIGHT)
	{
		while (++x <= WIDTH)
		{
			ft_put_pixel(mlx, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}*/
