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

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		offset; //incomplete

	mlx = mlx_init();
	if(!mlx)
		return(1);

	img.img = mlx_new_image(mlx, 1600, 800);
	img.addr = mlx_get_data_addr(
		img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_win =  mlx_new_window(mlx, 1600, 800, "test window");

	if(!mlx_win)
	{
		mlx_destroy_display(mlx_win);
		free(mlx);
		return(1);
	}

	mlx_loop(mlx);
//
	mlx_destroy_display(mlx_win);
	free(mlx);
}
