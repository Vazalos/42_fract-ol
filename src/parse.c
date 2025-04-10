/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:37:27 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/10 11:11:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_parse_name(int argc, char **argv)
{
	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0
			&& ft_strlen(argv[1]) == 10)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0
			&& ft_strlen(argv[1]) == 5)
		|| (argc == 2 && ft_strncmp(argv[1], "sin", 3) == 0
			&& ft_strlen(argv[1]) == 3))
	{
		return (1);
	}
	else if (argc == 2 && ft_strncmp(argv[1], "help", 4) == 0
		&& ft_strlen(argv[1]) == 4)
	{
		return (2);
	}
	else
		return (0);
}

void	ft_parse_fractal(t_data *mlx, char **argv)
{
	mlx->fractal_name = argv[1];
	if (ft_strncmp(mlx->fractal_name, "mandelbrot", 10) == 0)
		mlx->fractal_set = 1;
	if (ft_strncmp(mlx->fractal_name, "julia", 5) == 0)
		mlx->fractal_set = 2;
	if (ft_strncmp(mlx->fractal_name, "sin", 4) == 0)
		mlx->fractal_set = 3;
	if (mlx->fractal_set == 2)
	{
		ft_valid_julia_args(argv);
		mlx->julia.xr = ft_atod(argv[2]);
		mlx->julia.yi = ft_atod(argv[3]);
		mlx->toggle_julia = 0;
	}
	else
	{
		mlx->julia.xr = -.032;
		mlx->julia.yi = 0.7724;
		mlx->toggle_julia = 1;
	}
	mlx->sin_julia.xr = 0;
	mlx->sin_julia.yi = 0;
}
//good julias //492 681 // 168 516 // 309 526 // 309 456

void	ft_valid_julia_args(char **argv)
{
	static int	i;

	while (argv[2] && argv[2][i])
	{
		if (ft_strchr(".+-1234567890", argv[2][i]) != NULL)
			i++;
		else
		{
			ft_printf("Invalid arguments for julia!\n\n");
			ft_error();
			exit (0);
		}
	}
	i = 0;
	while (argv[3] && argv[3][i])
	{
		if (ft_strchr(".+-1234567890", argv[3][i]) != NULL)
			i++;
		else
		{
			ft_printf("Invalid arguments for julia!\n\n");
			ft_error();
			exit (0);
		}
	}
}
