/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:33:53 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/28 12:50:45 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_draw_image(t_data *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			if (mlx->fractal_set > 4)
				mlx->fractal_set = 1;
			if (mlx->fractal_set == 1)
				ft_mandelbrot(x, y, mlx);
			if (mlx->fractal_set == 2)
				ft_julia(x, y, mlx);
			if (mlx->fractal_set == 3)
				ft_sin(x, y, mlx);
			if (mlx->fractal_set == 4)
				ft_sin_julia(x, y, mlx);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	ft_visual_range(t_data *mlx)
{
	mlx->xr_range.min = mlx->min_xr + mlx->x_offset;
	mlx->xr_range.max = mlx->max_xr + mlx->x_offset;
	mlx->yi_range.min = mlx->min_yi + mlx->y_offset;
	mlx->yi_range.max = mlx->max_yi + mlx->y_offset;
}

int	ft_render_frame(t_data *mlx)
{
	ft_visual_range(mlx);
	ft_draw_image(mlx);
	mlx_put_image_to_window(mlx->connect, mlx->window, mlx->img.img_ptr, 0, 0);
	return (0);
}

void	ft_resume_render(t_data *mlx)
{
	mlx_loop_hook(mlx->connect, ft_render_frame, mlx);
}
