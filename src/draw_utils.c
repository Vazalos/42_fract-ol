/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:37:45 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/11 10:38:10 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_put_pixel(t_data *mlx, int x, int y, int color)
{
	char	*pixel_dest;

	pixel_dest = mlx->img.pix_addr +
		(y * mlx->img.line_len + x * (mlx->img.bpp / 8));
	*(unsigned int *)pixel_dest = color;
}
# define WHITE 0xFFFFFFFF

int	ft_draw_image(t_data *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			ft_mandelbrot(x, y, mlx);
			//ft_put_pixel(mlx, x, y, WHITE);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_render_frame(t_data *mlx)
{
	ft_visual_range(mlx);
	ft_draw_image(mlx);
	mlx_put_image_to_window(mlx->connect, mlx->window, mlx->img.img_ptr, 0, 0);
	return (0);
}
