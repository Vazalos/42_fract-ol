/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_profiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:17:05 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/26 11:20:50 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#define A 200
#define B 128

int	ft_color_profile(int i, t_data *mlx)
{
	int		color;

	if (mlx->color_profile > 3)
		mlx->color_profile = 0;
	mlx->j = mlx->max_iter / 10.0;
	mlx->k = mlx->max_iter / 4.0;
	mlx->l = mlx->max_iter / 1.5;
	if (mlx->color_profile == 0)
		color = ft_legacy_color(i, mlx);
	if (mlx->color_profile == 1)
		color = ft_2nd_color(i, mlx);
	if (mlx->color_profile == 2)
		color = ft_3rd_color(i, mlx);
	if (mlx->color_profile == 3)
		color = ft_4th_color(i, mlx);
	color = ft_encode_argb(255,
			ft_get_r(color) + mlx->red_shift,
			ft_get_g(color) + mlx->green_shift,
			ft_get_b(color) + mlx->blue_shift);
	return (color);
}

int	ft_legacy_color(int i, t_data *mlx)
{
	int	color;

	color = ft_encode_argb(255,
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(255, 50)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(180, 0)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(255, 200)));
	return (color);
}

int	ft_2nd_color(int i, t_data *mlx)
{
	int		color;
	double	d;

	d = mlx->max_iter;
	if (i >= d - mlx->j)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->j, d), ft_range(200, 250)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(200, 30)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(50, 40)));
	if (i < d - mlx->j && i >= d - mlx->k)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(0, 200)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(220, 200)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(220, 50)));
	if (i < d - mlx->k && i >= d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(0, 0)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(0, 220)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(A, 220)));
	if (i < d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, d - mlx->l), ft_range(20, 0)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(20, 0)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 200)));
	return (color);
}

int	ft_3rd_color(int i, t_data *mlx)
{
	int		color;
	double	d;

	d = mlx->max_iter;
	if (i >= d - mlx->j)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->j, d), ft_range(255, 255)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(127, 215)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(80, 0)));
	if (i < d - mlx->j && i >= d - mlx->k)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(255, 255)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(20, 127)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(147, 80)));
	if (i < d - mlx->k && i >= d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(128, 255)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(0, 20)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(B, 147)));
	if (i < d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 128)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 0)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 128)));
	return (color);
}

int	ft_4th_color(int i, t_data *mlx)
{
	int		color;
	double	d;

	d = mlx->max_iter;
	if (i >= d - mlx->j)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->j, d), ft_range(230, 240)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(200, 40)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(45, 50)));
	if (i < d - mlx->j && i >= d - mlx->k)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(220, 230)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(250, 200)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(40, 45)));
	if (i < d - mlx->k && i >= d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(30, 220)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(255, 250)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(50, 40)));
	if (i < d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, d - mlx->l), ft_range(10, 30)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 255)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(10, 50)));
	return (color);
}
