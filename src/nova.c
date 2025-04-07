/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:51:59 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/03 16:52:02 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>

void	calculate_nova(t_data *mlx);
unsigned int	ft_compare_roots(t_data *mlx);
void	ft_init_roots(t_complex *roots);
t_complex	ft_diff_to_root(t_complex z_newton, t_complex root);

double	ft_abs (double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	calculate_nova(t_data *mlx)
{
	t_complex	next;
	double		denominator;

	denominator	= (3 * (ft_squared(mlx->nova.xr) + ft_squared(mlx->nova.yi)));
	next.xr = (ft_squared(mlx->nova.xr) * ft_cubed(mlx->nova.xr)) + 
			(2 * ft_cubed(mlx->nova.xr) * ft_squared(mlx->nova.yi)) 
			- ft_squared(mlx->nova.xr) + (mlx->nova.xr * ft_squared(mlx->nova.yi)
			* ft_squared(mlx->nova.yi)) + (ft_squared(mlx->nova.yi)
			/denominator);
	next.yi = ((mlx->nova.yi * ((ft_squared(mlx->nova.xr) 
			* ft_squared(mlx->nova.xr)) + (2 * ft_squared(mlx->nova.xr)
			* ft_squared(mlx->nova.yi)) + (2 * mlx->nova.xr) 
			+ (ft_squared(mlx->nova.yi) * ft_squared(mlx->nova.yi))) 
			/ denominator));
	mlx->nova.xr = next.xr;
	mlx->nova.yi = next.yi;
}

unsigned int	ft_compare_roots(t_data *mlx)
{
	static t_complex	roots[3];
	t_complex			diff;

	ft_init_roots(roots);
	diff = ft_diff_to_root(mlx->nova, roots[0]);
	if ((ft_abs(diff.xr) < mlx->nova_esc_val) && (ft_abs(diff.yi) < mlx->nova_esc_val))
		return (1);
	diff = ft_diff_to_root(mlx->nova, roots[1]);
	if ((ft_abs(diff.xr) < mlx->nova_esc_val) && (ft_abs(diff.yi) < mlx->nova_esc_val))
		return (2);
	diff = ft_diff_to_root(mlx->nova, roots[2]);
	if ((ft_abs(diff.xr) < mlx->nova_esc_val) && (ft_abs(diff.yi) < mlx->nova_esc_val))
		return (3);
	else
		return (0);
}

void	ft_init_roots(t_complex *roots)
{
	static unsigned int	set;

	if (!set)
	{
		roots[0] = (t_complex){1, 0};
		roots[1] = (t_complex){0.5, 0.866025};
		roots[2] = (t_complex){0.5, -0.866025};
		set = 1;
	}
}

t_complex	ft_diff_to_root(t_complex nova, t_complex root)
{
	t_complex	diff;

	diff.xr = (nova.xr - root.xr);
	diff.yi = (nova.yi - root.yi);
	//printf("nxy %f %f rxy %f %f\n", nova.xr, nova.yi, root.xr, root.yi);
	return (diff);
}

void	ft_nova(int x, int y, t_data *mlx)
{
	int			i;
	int			root;
	int			color;

	i = 0;
	mlx->nova.xr = (ft_map(x, mlx->win_xrange, mlx->xr_range) * mlx->zoom) + mlx->x_offset;
	mlx->nova.yi = (ft_map(y, mlx->win_yrange, mlx->yi_range) * mlx->zoom) + mlx->y_offset;
	while (i++ < mlx->max_iter)
	{
		calculate_nova(mlx);
		root = ft_compare_roots(mlx);
		if (root != 0)
		{

			color = ft_color_profile(i, mlx); // probably no enough
			if (root == 1)
				ft_put_pixel(mlx, x, y, RED);
			if (root == 2)
				ft_put_pixel(mlx, x, y, GREEN);
			if (root == 3)
				ft_put_pixel(mlx, x, y, BLUE);
			return ;
		}
	}
	ft_put_pixel(mlx, x, y, BLACK);
}
