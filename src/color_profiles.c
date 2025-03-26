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
		ft_legacy_color(i, mlx);
	if (mlx->color_profile == 1)
		ft_2nd_color(i, mlx);
	if (mlx->color_profile == 2)
		ft_3rd_color(i, mlx);
	if (mlx->color_profile == 3)
		ft_4th_color(i, mlx);
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

	color = ft_encode_argb(255,
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(205, 50)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(20, 190)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(0, 200)));
	return (color);
}

int	ft_3rd_color(int i, t_data *mlx)
{
	int	color;

	color = ft_encode_argb(255,
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(60, 0)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(50, 200)),
			ft_map(i, ft_range(0, mlx->max_iter), ft_range(150, 0)));
	return (color);
}

int	ft_4th_color(int i, t_data *mlx)
{
	int	color;

	if (i >= mlx->max_iter - 10)
		color = ft_encode_argb(255,
				ft_map(i, ft_range(mlx->max_iter - 10, mlx->max_iter),
					ft_range(80, 40)),
				ft_map(i, ft_range(mlx->max_iter - 10, mlx->max_iter),
					ft_range(180, 90)),
				ft_map(i, ft_range(mlx->max_iter - 10, mlx->max_iter),
					ft_range(120, 60)));
	else
		color = ft_encode_argb(255,
				ft_map(i, ft_range(0, mlx->max_iter - 10), ft_range(0, 80)),
				ft_map(i, ft_range(0, mlx->max_iter - 10), ft_range(0, 180)),
				ft_map(i, ft_range(0, mlx->max_iter - 10), ft_range(0, 120)));
	return (color);
}
