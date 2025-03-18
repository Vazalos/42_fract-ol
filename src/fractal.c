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
	mlx->c.xr = ft_map(x, mlx->win_xrange, mlx->fract_xrange);
	mlx->c.yi = ft_map(y, mlx->win_yrange, mlx->fract_yrange);
	while (++i <= mlx->max_iter)
	{
		z_tmp = ft_squared(mlx->z.xr) - ft_squared(mlx->z.yi) + mlx->c.xr;
		mlx->z.yi = (2 * mlx->z.xr * mlx->z.yi) + mlx->c.yi;
		mlx->z.xr = z_tmp;
		if (ft_squared(mlx->z.xr) + ft_squared(mlx->z.yi) > mlx->escape_val)
		{
			color = ft_encode_argb(255,
					ft_map(i, ft_range(0, mlx->max_iter), ft_range(255, 50)),
					ft_map(i, ft_range(0, mlx->max_iter), ft_range(180, 0)),
					ft_map(i, ft_range(0, mlx->max_iter), ft_range(255, 200)));
			ft_put_pixel(mlx, x, y, color);
			return ;
		}
	}
	ft_put_pixel(mlx, x, y, BLACK);
}
/*
void	ft_julia(int x, int y, t_data *mlx)
{

}*/
			//color = ft_encode_argb(255, 255*i/42, 255*i/42, 255);
			//color = ft_map(i, mlx->color_range, mlx->color_iter);
			//printf("iter:%d omin:%f omax:%f, nmin:%f nmax:%f ", i
//* *///,mlx->color_range.min, mlx->color_range.max, mlx->color_iter.min
//, mlx->color_iter.max);
			//printf("%d\n", color);
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
