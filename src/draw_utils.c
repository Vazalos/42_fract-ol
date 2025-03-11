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

void	ft_mlx_put_pixel(t_data *mlx, int x, int y, int color)
{
	char	*pixel_dest;

	pixel_dest = mlx->img_addr +
		(y * mlx->img_line_len + x * (mlx->img_bpp / 8));
	*(unsigned int *)pixel_dest = color;
}

int	ft_draw_texture(t_data *mlx)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = ft_encode_argb(0, 100, 0, 100);
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			ft_mlx_put_pixel(mlx, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_render_frame(t_data *mlx)
{
	ft_draw_texture(mlx);
	mlx_put_image_to_window(mlx->connect, mlx->window, mlx->img, 0, 0);
	return (0);
}
