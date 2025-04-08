/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:37:45 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/28 13:05:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_put_pixel(t_data *mlx, int x, int y, int color)
{
	char	*pixel_dest;

	pixel_dest = mlx->img.pix_addr
		+ (y * mlx->img.line_len + x * (mlx->img.bpp / 8));
	*(unsigned int *)pixel_dest = color;
}

void	ft_reset_view(t_data *mlx)
{
	mlx->y_offset = 0;
	mlx->x_offset = 0;
	mlx->zoom = ZOOM;
	mlx->zoom_level = mlx->zoom;
	mlx->min_xr = -2.0;
	mlx->max_xr = 2.0;
	mlx->min_yi = -2.0;
	mlx->max_yi = 2.0;
	mlx->scale_x = (mlx->max_xr - mlx->min_xr) / (WIDTH - 1);
	mlx->scale_y = (mlx->max_yi - mlx->min_yi) / (HEIGHT - 1);
}

void	ft_cursor_offset(int x, int y, t_data *mlx, int zoomin)
{
	double	cursor_xr;
	double	cursor_yi;

	cursor_xr = mlx->min_xr + (x * (mlx->scale_x));
	cursor_yi = mlx->max_yi - ((WIDTH - y) * (mlx->scale_y));
	if (zoomin == 0)
	{
		mlx->min_xr = cursor_xr + (mlx->min_xr - cursor_xr) * mlx->zoom;
		mlx->max_xr = cursor_xr + (mlx->max_xr - cursor_xr) * mlx->zoom;
		mlx->min_yi = cursor_yi + (mlx->min_yi - cursor_yi) * mlx->zoom;
		mlx->max_yi = cursor_yi + (mlx->max_yi - cursor_yi) * mlx->zoom;
		mlx->zoom_level *= mlx->zoom;
	}
	if (zoomin == 1)
	{
		mlx->min_xr = cursor_xr + (mlx->min_xr - cursor_xr) / mlx->zoom;
		mlx->max_xr = cursor_xr + (mlx->max_xr - cursor_xr) / mlx->zoom;
		mlx->min_yi = cursor_yi + (mlx->min_yi - cursor_yi) / mlx->zoom;
		mlx->max_yi = cursor_yi + (mlx->max_yi - cursor_yi) / mlx->zoom;
		mlx->zoom_level /= mlx->zoom;
	}
	mlx->scale_x = (mlx->max_xr - mlx->min_xr) / (WIDTH - 1);
	mlx->scale_y = (mlx->max_yi - mlx->min_yi) / (HEIGHT - 1);
}
