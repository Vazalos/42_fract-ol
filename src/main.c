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

int	ft_free_all(t_data *mlx)
{
	if(mlx->img.img_ptr != NULL)
		mlx_destroy_image(mlx->connect, mlx->img.img_ptr);
	if(mlx->window != NULL)
		mlx_destroy_window(mlx->connect, mlx->window);
	mlx_destroy_display(mlx->connect);
	free(mlx->connect);
	return (exit(0), 0);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		ft_init_mlx(&mlx, argv[1]);
		ft_render_fractal(0, 0, &mlx, argv); //WHAT ARE THE ARGUMENTS #! and #2
		ft_render_frame(&mlx);
		//mlx_loop_hook(mlx.connect, render_frame, &mlx);
		mlx_mouse_hook(mlx.window, ft_on_scroll, &mlx);
		mlx_hook(mlx.window, KeyPress, KeyPressMask, ft_on_keypress, &mlx);
		mlx_hook(mlx.window, DestroyNotify, 0, ft_free_all, &mlx);
		mlx_loop(mlx.connect);
	}
	else
		ft_printf("error");
}
