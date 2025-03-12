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


void	ft_render_fractal(int x, int y, t_data *mlx, char **argv)
{
	(void)argv;
	t_complex_num	z;
	t_complex_num	c;
	int				i;

	z.x = 0;
	z.y = 0;
	c.x = ft_window_scale(x, -2, 2, WIDTH);
	c.y = ft_window_scale(y, 2, -2, HEIGHT);
	while(		
	((z.x * z.x) - (z.y * z.y)) + (2 * );
}

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
			ft_mlx_put_pixel(mlx, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
