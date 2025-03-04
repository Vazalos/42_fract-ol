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

void	mlx_put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_texture(t_data img)
{
	int x = 0;
	int y = 0;

	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			mlx_put_pixel(&img, x, y, 0x00FF0000+/*((x*255)/WIDTH)+*/((y*65280)/HEIGHT));
			x++;
		}
		x = 0;
		y++;
	}
}

int	main(void)
{
	void	*mlx_connect;
	void	*mlx_window;
	t_data	img;

	mlx_connect = mlx_init();
	if (!mlx_connect)
		return (1);
	mlx_window = mlx_new_window(mlx_connect, WIDTH, HEIGHT, "test window");
	if (!mlx_window)
	{
		mlx_destroy_display(mlx_window);
		free(mlx_connect);
		return (1);
	}
	img.img = mlx_new_image(mlx_connect, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//
	draw_texture(img);
	//
	mlx_put_image_to_window(mlx_connect, mlx_window, img.img, 0, 0);
	mlx_loop(mlx_connect);
}

	/*
	mlx_destroy_display(mlx_window);
	free(mlx_connect);*/
