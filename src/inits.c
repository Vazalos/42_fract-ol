/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:31:36 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/12 15:26:00 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_range	ft_init_range(double min, double max)
{
	t_range range;

	range.min = min;
	range.max = max;
	return (range);
}

int	ft_init_mlx(t_data *mlx, char *name)
{
	mlx->connect = mlx_init();
	if (!mlx->connect)
		return (MLX_ERROR);
	mlx->fractal_name = name;
	ft_init_values(mlx);
	mlx->window = mlx_new_window(mlx->connect, WIDTH, HEIGHT, name);
	mlx->img.img_ptr = mlx_new_image(mlx->connect, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr || !mlx->window)
		ft_free_all(mlx);
	mlx->img.pix_addr = mlx_get_data_addr(
			mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	return(0);
}

void ft_init_values(t_data *mlx)
{
	mlx->x_offset = 0;
	mlx->y_offset = 0;
	mlx->win_xrange = ft_init_range(0, WIDTH);
	mlx->win_yrange = ft_init_range(0, HEIGHT);
	mlx->min_xr = -2.0;
	mlx->max_xr = 2.0;
	mlx->min_yi = -2.0;
	mlx->max_yi = 2.0;
	mlx->xr_range = ft_init_range(mlx->min_xr, mlx->max_xr);
	mlx->yi_range = ft_init_range(mlx->max_yi, mlx->min_yi);
	mlx->scale_x = (mlx->max_xr - mlx->min_xr)/(WIDTH - 1);
	mlx->scale_y = (mlx->max_yi - mlx->min_yi)/(HEIGHT - 1);
	mlx->z.xr = 0;
	mlx->z.yi = 0;
	mlx->c.xr = 0;
	mlx->c.yi = 0; 
	mlx->max_iter = MAX_ITER;
	mlx->escape_val = 4;
	mlx->color_profile = 0;
	mlx->color_range = ft_init_range(WHITE, BLACK);
	mlx->color_iter = ft_init_range(0, mlx->max_iter);
	mlx->zoom = ZOOM;
	mlx->zoom_level= mlx->zoom;
}

