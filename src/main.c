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
#include <stdlib.h>
#define WIDTH 1600
#define HEIGHT 800
#define MLX_ERROR 1

int	free_all(t_data *mlx)
{
	if(mlx->img != NULL)
		mlx_destroy_image(mlx->connect, mlx->img);
	if(mlx->window != NULL)
		mlx_destroy_window(mlx->connect, mlx->window);
	mlx_destroy_display(mlx->connect);
	free(mlx->connect);
	return (exit(0), 0);
}

void	mlx_put_pixel(t_data *mlx, int x, int y, int color)
{
	char	*pixel_dest;

	if(!mlx->window)
		return;
	pixel_dest = mlx->img_addr + (y * mlx->img_line_len + x * (mlx->img_bpp / 8));
	*(unsigned int *)pixel_dest = color;
}

int	draw_texture(t_data *mlx)
{
	int x = 0;
	int y = 0;
	static int i;
	static int j;
	int color;
	static int flag;

//
			if(i % 4 == 0)
				color = encode_argb(0, i, i/5, i/5);
			if((i+1) % 4 == 0)
				color = encode_argb(0, i/5, i, i/5);
			if((i+2) % 4 == 0)
				color = encode_argb(0, i/5, i/5, i);
			if((i+3) % 4 == 0)
				color = encode_argb(0, i, i/5, i);
			if(i <= 254 && j % 40 == 0 && flag == 0)
			{
				i++;
				if(i == 255)
					flag = 1;

			}
			if(i >= 1 && j % 10 == 0 && flag == 1)
			{		
				i--;
				if(i == 0)
					flag = 0;
			}
			j++;

//
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			mlx_put_pixel(mlx, x, y, color);
			//encode_argb(0, 0, 255, (((x+y)/2)*255) / ((WIDTH+HEIGHT)/2))
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	on_keypress(int keysym, t_data *mlx)
{
	if(keysym == XK_Escape)
		free_all(mlx);
	return (0);
}

int	render_frame(t_data *mlx)
{
	draw_texture(mlx);
	mlx_put_image_to_window(mlx->connect, mlx->window, mlx->img, 0, 0);
	return(0);
}

int	main(void)
{
	t_data	mlx;

	mlx = (t_data){NULL, NULL, NULL, NULL, 0, 0, 0};
	mlx.connect = mlx_init();
	if (!mlx.connect)
		return (MLX_ERROR);
	mlx.window = mlx_new_window(mlx.connect, WIDTH, HEIGHT, "ganda fract-ol");
	mlx.img = mlx_new_image(mlx.connect, WIDTH, HEIGHT);
	if (!mlx.img || !mlx.window)
		free_all(&mlx);
	mlx.img_addr = mlx_get_data_addr(
			mlx.img, &mlx.img_bpp, &mlx.img_line_len, &mlx.img_endian);	
	mlx_loop_hook(mlx.connect, render_frame, &mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, on_keypress, &mlx);
	mlx_loop(mlx.connect);
}
/*
y	mlx_destroy_image(mlx.connect, mlx.img);
	mlx_destroy_window(mlx.connect, mlx.window);
	mlx_destroy_display(mlx.connect);
	free(mlx.connect);
*/
