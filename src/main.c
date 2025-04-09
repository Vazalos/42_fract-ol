/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:53:33 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/26 15:56:31 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_data	mlx;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "sin", 3) == 0))
	{
		ft_parse_fractal(&mlx, argv);
		ft_init_values(&mlx);
		ft_init_mlx(&mlx);
		ft_render_frame(&mlx);
		ft_event_handler(&mlx);
		mlx_loop(mlx.connect);
	}
	else if (argc == 2 && ft_strncmp(argv[1], "help", 4) == 0)
		ft_control_help();
	else
		ft_error();
}

int	ft_free_all(t_data *mlx)
{
	if (mlx->img.img_ptr != NULL)
		mlx_destroy_image(mlx->connect, mlx->img.img_ptr);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->connect, mlx->window);
	mlx_destroy_display(mlx->connect);
	free(mlx->connect);
	exit (0);
	return (0);
}

void	ft_error(void)
{
	ft_printf("Valid fractal names are 'mandelbrot', 'julia' and 'sin'\n"
		"Julia additionally requires 2 numbers,"
		"recommended range {-2.0, 2.0}\n"
		"There is information on controls the window header\n"
		"For more detailed control list type ./fractol help\n");
}

void	ft_control_help(void)
{
	ft_printf(
		"     .: MOVE & ZOOM :.\n"
		"WASD/ARROWS  -  moves the viewport\n"
		"Scroll Up    -  zoom in\n"
		"Scroll Down  -  zoom out\n"
		"Left Click   -  super zoom in\n"
		"Right Click  -  super zoom out\n\n"
		"      [ R ]  -  reset zoom & viewport\n"
		"        .: COLOR :.\n"
		"      [ E ]  -  change color profile (4 presets)\n\n"
		"     [1][2]  -  increase/decrease RED color value\n"
		"     [3][4]  -  increase/decrease GREEN color value\n"
		"     [5][6]  -  increase/decrease BLUE color value\n"
		"      [ Q ]  -  reset all color values\n"
		"   .: FRACTAL SELECT :.\n"
		"      [ M ]  -  Mandelbrot Set\n"
		"      [ J ]  -  Mandelbrot's Julia set\n"
		"      [ N ]  -  Sin set\n"
		"      [ H ]  -  Sin's Julia set\n"
		"  .: FRACTAL TRANSFORM :.\n"
		"Scroll Click -  change julia constant (also switches to julia)\n"
		"      [ T ]  -  toggle julia movement (can break switching fractals)\n"
		"     [F][G]  -  increase/decrease fractal depth (higher = slower)\n\n"
		);
}
