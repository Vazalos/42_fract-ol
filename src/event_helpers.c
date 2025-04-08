/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:43:10 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/08 15:50:03 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_color_shift(int keysym, t_data *mlx)
{
	if (keysym == XK_e)
		mlx->color_profile = mlx->color_profile + 1;
	if (keysym == XK_q)
	{
		mlx->red_shift = 0;
		mlx->green_shift = 0;
		mlx->blue_shift = 0;
	}
	if (keysym == XK_1)
		mlx->red_shift -= COLOR_SHIFT;
	if (keysym == XK_2)
		mlx->red_shift += COLOR_SHIFT;
	if (keysym == XK_3)
		mlx->green_shift -= COLOR_SHIFT;
	if (keysym == XK_4)
		mlx->green_shift += COLOR_SHIFT;
	if (keysym == XK_5)
		mlx->blue_shift -= COLOR_SHIFT;
	if (keysym == XK_6)
		mlx->blue_shift += COLOR_SHIFT;
}

void	ft_toggle_julia(t_data *mlx)
{
	if (mlx->fractal_set == 2 || mlx->fractal_set == 4)
	{
		if (mlx->toggle_julia == 1)
			mlx->toggle_julia = 0;
		else
			mlx->toggle_julia = 1;
		ft_resume_render(mlx);
	}
}

int	ft_shift_fractal(int x, int y, t_data *mlx)
{
	if (mlx->fractal_set == 1)
	{
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
		mlx->fractal_set = 2;
	}
	if (mlx->fractal_set == 2)
	{
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
	}
	if (mlx->fractal_set == 3)
	{
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
		mlx->fractal_set = 4;
	}
	if (mlx->fractal_set == 4)
	{
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
	}
	return (0);
}

void	ft_select_fractal(int keysym, t_data *mlx)
{
	if (keysym == XK_m)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 1;
		mlx->toggle_julia = 0;
		ft_reset_view(mlx);
		ft_resume_render(mlx);
	}
	if (keysym == XK_j)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 2;
		mlx->toggle_julia = 0;
		ft_reset_view(mlx);
		ft_resume_render(mlx);
	}
	if (keysym == XK_n)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 3;
		mlx->toggle_julia = 0;
		ft_reset_view(mlx);
		ft_resume_render(mlx);
	}
	if (keysym == XK_h)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 4;
		mlx->toggle_julia = 0;
		ft_reset_view(mlx);
		ft_resume_render(mlx);
	}
}

