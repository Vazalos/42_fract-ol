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
	int max;
	int n;

	max = mlx->max_iter;
	n = max/2;
	if (i < max - n)
		color = ft_encode_argb(255, 0, i * 220 / (max - n) , 10 + i * 235 / (max - n));
	else
		color = ft_encode_argb(255, 255, 100, 100);
	return (color);
}

int	ft_3rd_color(int i, t_data *mlx)
{
	int	color;

	color = ft_encode_argb(255,
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(150, 0)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(0, 255)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(150, 0)));
	return (color);
}

int	ft_4th_color(int i, t_data *mlx)
{
	int	color;
	int max;
	int n;
	double m;

	max = mlx->max_iter;
	n = max/8;
	m = 3;
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
