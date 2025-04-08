/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:31:36 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/28 13:04:52 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_init_mlx(t_data *mlx, char **argv)
{
	mlx->connect = mlx_init();
	if (!mlx->connect)
		return (MLX_ERROR);
	ft_parse_fractal(mlx, argv);
	ft_init_values(mlx);
	mlx->window = mlx_new_window(mlx->connect, WIDTH, HEIGHT,
			"ARROWS/WASD move   MOUSE zoom & shift   [1]-[6][Q][E] color   "
			"[R] reset   [F][G] depth   [M]andelbrot   [J]ulia   [N]ova");
	mlx->img.img_ptr = mlx_new_image(mlx->connect, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr || !mlx->window)
		ft_free_all(mlx);
	mlx->img.pix_addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
	return (0);
}

void	ft_parse_fractal(t_data *mlx, char **argv)
{
	mlx->fractal_name = argv[1];
	if (ft_strncmp(mlx->fractal_name, "mandelbrot", 10) == 0)
		mlx->fractal_set = 1;
	if (ft_strncmp(mlx->fractal_name, "julia", 5) == 0)
		mlx->fractal_set = 2;
	if (ft_strncmp(mlx->fractal_name, "nova", 4) == 0)
		mlx->fractal_set = 3;
	if (mlx->fractal_set == 2)
	{
		mlx->julia.xr = ft_atod(argv[2]);
		mlx->julia.yi = ft_atod(argv[3]);
	}
	else
	{
		mlx->julia.xr = -.032;
		mlx->julia.yi = 0.7724;
	}
}
//good julias //492 681 // 168 516 // 309 526 // 309 456

t_range	ft_range(double min, double max)
{
	t_range	r;

	r.min = min;
	r.max = max;
	return (r);
}

void	ft_init_values(t_data *mlx)
{
	mlx->z.xr = 0;
	mlx->z.yi = 0;
	mlx->c.xr = 0;
	mlx->c.yi = 0;
	mlx->min_xr = -2.0;
	mlx->max_xr = 2.0;
	mlx->min_yi = -2.0;
	mlx->max_yi = 2.0;
	mlx->win_xrange = ft_range(0, WIDTH);
	mlx->win_yrange = ft_range(0, HEIGHT);
	mlx->xr_range = ft_range(mlx->min_xr, mlx->max_xr);
	mlx->yi_range = ft_range(mlx->max_yi, mlx->min_yi);
	mlx->x_offset = 0;
	mlx->y_offset = 0;
	mlx->zoom = ZOOM;
	mlx->zoom_level = mlx->zoom;
	mlx->scale_x = (mlx->max_xr - mlx->min_xr) / (WIDTH - 1);
	mlx->scale_y = (mlx->max_yi - mlx->min_yi) / (HEIGHT - 1);
	mlx->max_iter = MAX_ITER;
	mlx->escape_val = 4;
	mlx->color_profile = 0;
	mlx->red_shift = 0;
	mlx->green_shift = 0;
	mlx->blue_shift = 0;
	mlx->toggle = 0;
}
