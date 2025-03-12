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
	t_range		new_scale;
	t_range		old_scale;

	z.x = 0;
	z.y = 0;
	c.x = ft_map(x, mlx->win_xr, mlx->fract_xr);
	c.y = ft_map(x, mlx->win_yr, mlx->fract_yr);
	/*while(		
	((z.x * z.x) - (z.y * z.y)) + (2 * );*/
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
			ft_mlx_put_pixel(mlx, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}*/
