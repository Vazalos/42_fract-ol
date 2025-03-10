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
#include <X11/X.h>
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

	pixel_dest = mlx->img_addr + (y * mlx->img_line_len + x * (mlx->img_bpp / 8));
	*(unsigned int *)pixel_dest = color;
}

int	draw_texture(t_data *mlx)
{
	int x = 0;
	int y = 0;
	int color;
	
	color = encode_argb(0, 100, 0, 100);
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			mlx_put_pixel(mlx, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	render_frame(t_data *mlx)
{
	draw_texture(mlx);
	mlx_put_image_to_window(mlx->connect, mlx->window, mlx->img, 0, 0);
	return (0);
}

int on_scroll(int keysym, int x, int y, t_data *mlx)
{
	(void)x;
	(void)y;
	printf("Keyrelease: %d, x %d, y %d\n", keysym, x, y);
	if(keysym == 4)
		printf("scroll up\n");
	if(keysym == 5)
		printf("scroll down\n");
	render_frame(mlx);
	return (0);
}

int	on_keypress(int keysym, t_data *mlx)
{    
	printf("Keyrelease: %d\n", keysym);
	if(keysym == XK_Escape)
		free_all(mlx);
	if(keysym == XK_Up || keysym == XK_w)
		printf("UP\n");
	if(keysym == XK_Down || keysym == XK_s)
		printf("DOWN\n");
	if(keysym == XK_Left || keysym == XK_a)
		printf("LEFT\n");
	if(keysym == XK_Right || keysym == XK_d)
		printf("RIGHT\n");
	render_frame(mlx);
	return (0);
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
	render_frame(&mlx);
	//mlx_loop_hook(mlx.connect, render_frame, &mlx);
	mlx_mouse_hook(mlx.window, on_scroll, &mlx);
	mlx_hook(mlx.window, KeyPress, KeyPressMask, on_keypress, &mlx);
	mlx_hook(mlx.window, DestroyNotify, 0, free_all, &mlx);
	mlx_loop(mlx.connect);
}
