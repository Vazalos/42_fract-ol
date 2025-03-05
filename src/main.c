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
#define WIDTH 1600
#define HEIGHT 800
#define MLX_ERROR 1

int	free_all(t_data *mlx)
{
	mlx_destroy_image(mlx->connect, mlx->img);
	mlx_destroy_window(mlx->connect, mlx->window);
	mlx_destroy_display(mlx->connect);
	free(mlx->connect);
	return (0);
}

void	mlx_put_pixel(t_data mlx, int x, int y, int color)
{
	char	*pixel_dest;

	if(!mlx.window)
		return;
	pixel_dest = mlx.img_addr + (y * mlx.img_line_len + x * (mlx.img_bpp / 8));
	*(unsigned int *)pixel_dest = color;
}

int	draw_texture(t_data *mlx)
{
	int x = 0;
	int y = 0;
	static int i;

	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			mlx_put_pixel(*mlx, x, y, encode_argb(0, 0+((i++)/10000), 255, (((x+y)/2)*255) / ((WIDTH+HEIGHT)/2)));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	on_keypress(int keysym, t_data mlx)
{
	if(keysym == XK_Escape)
	{
		mlx_destroy_image(mlx.connect, mlx.img);
		mlx_destroy_window(mlx.connect, mlx.window);
		mlx_destroy_display(mlx.connect);
		free(mlx.connect);
	}
	return (0);
}



int	main(void)
{
	t_data	mlx;

	mlx.connect = mlx_init();
	if (!mlx.connect)
		return (MLX_ERROR);
	mlx.window = mlx_new_window(mlx.connect, WIDTH, HEIGHT, "ganda fract-ol");
	if (!mlx.window)
	{
		free(mlx.connect);
		return (MLX_ERROR);
	}
	mlx.img = mlx_new_image(mlx.connect, WIDTH, HEIGHT);
	mlx.img_addr = mlx_get_data_addr(
			mlx.img, &mlx.img_bpp, &mlx.img_line_len, &mlx.img_endian);	


	draw_texture(&mlx);
	mlx_put_image_to_window(mlx.connect, mlx.window, mlx.img, 0, 0);

	mlx_loop_hook(mlx.connect, draw_texture, &mlx);
	mlx_loop(mlx.connect);
}
/*
y	mlx_destroy_image(mlx.connect, mlx.img);
	mlx_destroy_window(mlx.connect, mlx.window);
	mlx_destroy_display(mlx.connect);
	free(mlx.connect);
*/
