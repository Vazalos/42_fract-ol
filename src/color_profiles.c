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

int	ft_legacy_color(int i, t_data *mlx);
int	ft_2nd_color(int i, t_data *mlx);
int	ft_3rd_color(int i, t_data *mlx);
int	ft_4th_color(int i, t_data *mlx);

int	ft_color_profile(int i, t_data *mlx)
{
	int		color;

	if (mlx->color_profile > 3)
		mlx->color_profile = 0;
	mlx->j = mlx->max_iter/10.0;
	mlx->k = mlx->max_iter/5.0;
	mlx->l = mlx->max_iter/2.0;
	if (mlx->color_profile == 0)
		color = ft_legacy_color(i, mlx);
	if (mlx->color_profile == 1)
		color = ft_2nd_color(i, mlx);
	if (mlx->color_profile == 2)
		color = ft_3rd_color(i, mlx);
	if (mlx->color_profile == 3)
		color = ft_4th_color(i, mlx);
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
	int	color;
	double d;

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
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(200, 220)));
	if (i < d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, d - mlx->l), ft_range(20, 0)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(20, 0)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 200)));
	return (color);
}

int	ft_3rd_color(int i, t_data *mlx)
{
	int	color;
	double d;

	d = mlx->max_iter;
	if (i >= d - mlx->j)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->j, d), ft_range(240, 240)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(240, 40)),
				ft_map(i, ft_range(d - mlx->j, d), ft_range(30, 50)));
	if (i < d - mlx->j && i >= d - mlx->k)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(240, 240)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(240, 240)),
				ft_map(i, ft_range(d - mlx->k, d - mlx->j), ft_range(30, 30)));
	if (i < d - mlx->l && i >= d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(30, 240)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(255, 240)),
				ft_map(i, ft_range(d - mlx->l, d - mlx->k), ft_range(50, 30)));
	if (i < d - mlx->l)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, d - mlx->l), ft_range(10, 30)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(0, 255)),
				ft_map(i, ft_range(0, d - mlx->l), ft_range(10, 50)));
	return (color);
}

int	ft_4th_color(int i, t_data *mlx)
{
	int	color;
	double max;
	double n;
	double m;

	max = mlx->max_iter;
	n = max/8;
	m = 4;
	if (i >= max - n)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(max - n, max), ft_range(200, 250)),
				ft_map(i, ft_range(max - n, max), ft_range(200, 30)),
				ft_map(i, ft_range(max - n, max), ft_range(50, 40)));
	if (i < max - n && i >= max - (n * m))
		color = ft_encode_argb(255,
				ft_map(i, ft_range(max - (n * m), max - n), ft_range(50, 200)),
				ft_map(i, ft_range(max - (n * m), max - n), ft_range(255, 200)),
				ft_map(i, ft_range(max - (n * m), max - n), ft_range(70, 50)));
	if (i < max - (n * m))
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, max - (n * m)), ft_range(10, 50)),
				ft_map(i, ft_range(0, max - (n * m)), ft_range(0, 255)),
				ft_map(i, ft_range(0, max - (n * m)), ft_range(10, 70)));
	return (color);
}

/*
	int	color;
	int max;
	int n;
	double m;

	max = mlx->max_iter;
	n = 10;
	m = 1;
	if (i >= MAX_ITER)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(MAX_ITER, max), ft_range(200, 255)),
				ft_map(i, ft_range(MAX_ITER, max), ft_range(200, 0)),
				ft_map(i, ft_range(MAX_ITER, max), ft_range(50, 0)));
	if (i < MAX_ITER && i >= MAX_ITER - (n * m))
		color = ft_encode_argb(255,
				ft_map(i, ft_range(MAX_ITER - (n * m), MAX_ITER), ft_range(60, 200)),
				ft_map(i, ft_range(MAX_ITER - (n * m), MAX_ITER), ft_range(200, 200)),
				ft_map(i, ft_range(MAX_ITER - (n * m), MAX_ITER), ft_range(90, 50)));
	if (i < MAX_ITER - (n * m))
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, MAX_ITER - (n * m)), ft_range(0, 60)),
				ft_map(i, ft_range(0, MAX_ITER - (n * m)), ft_range(0, 200)),
				ft_map(i, ft_range(0, MAX_ITER - (n * m)), ft_range(0, 90)));
	return (color);
*/
