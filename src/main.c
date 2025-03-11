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
	if(mlx->img != NULL)
		mlx_destroy_image(mlx->connect, mlx->img);
	if(mlx->window != NULL)
		mlx_destroy_window(mlx->connect, mlx->window);
	mlx_destroy_display(mlx->connect);
	free(mlx->connect);
	return (exit(0), 0);
}

int	ft_init_mlx(t_data *mlx, char *name)
{
	mlx->connect = mlx_init();
	if (!mlx->connect)
		return (MLX_ERROR);
	mlx->fractal_name = name;
	mlx->window = mlx_new_window(mlx->connect, WIDTH, HEIGHT, name);
	mlx->img = mlx_new_image(mlx->connect, WIDTH, HEIGHT);
	if (!mlx->img || !mlx->window)
		ft_free_all(mlx);
	mlx->img_addr = mlx_get_data_addr(
			mlx->img, &mlx->img_bpp, &mlx->img_line_len, &mlx->img_endian);
	return(0);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		ft_init_mlx(&mlx, argv[1]);
		ft_fractal(&mlx, argv);
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
