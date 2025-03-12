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

void ft_init_values(t_data *mlx)
{
	mlx->win_xr = ft_init_range(0, WIDTH);
	mlx->win_yr = ft_init_range(0, HEIGHT);
	mlx->fract_xr = ft_init_range(-2, 2);
	mlx->fract_yr = ft_init_range(2, -2);
	mlx->max_iterations = 42;
	mlx->color_range = ft_init_range(WHITE, BLACK);
	mlx->color_iter = ft_init_range(0, mlx->max_iterations);
}

int	ft_init_mlx(t_data *mlx, char *name)
{
	mlx->connect = mlx_init();
	if (!mlx->connect)
		return (MLX_ERROR);
	mlx->fractal_name = name;
	mlx->window = mlx_new_window(mlx->connect, WIDTH, HEIGHT, name);
	mlx->img.img_ptr = mlx_new_image(mlx->connect, WIDTH, HEIGHT);
	if (mlx->img.img_ptr || !mlx->window)
		ft_free_all(mlx);
	mlx->img.pix_addr = mlx_get_data_addr(
			mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	return(0);
}
