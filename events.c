/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:51 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/28 13:05:44 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>
#include <stdio.h>

void	ft_event_handler(t_data *mlx)
{
	mlx_mouse_hook(mlx->window, ft_on_scroll, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_on_keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, 0, ft_free_all, mlx);
}

int ft_on_scroll(int button, int x, int y, t_data *mlx)
{
	if(button == 1)
	{
		mlx->zoom *= 50;
		ft_cursor_offset(x, y, mlx, 1);
		mlx->zoom /= 50;
	}
	if(button == 3)
	{
		mlx->zoom *= 25;
		ft_cursor_offset(x, y, mlx, 0);
		mlx->zoom /= 25;
	}
	if(button == 4)
		ft_cursor_offset(x, y, mlx, 1);
	if(button == 5)
		ft_cursor_offset(x, y, mlx, 0);
	ft_render_frame(mlx);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *mlx)
{   
	if(keysym == XK_Escape)
		ft_free_all(mlx);
	if(keysym == XK_r)
		ft_reset_view(mlx);
	if(keysym == XK_t)
		mlx->fractal_set = mlx->fractal_set + 1;
	if(keysym == XK_y)
		mlx->fractal_set = mlx->fractal_set - 1;
	if(keysym == XK_c)
		mlx->color_profile = mlx->color_profile + 1;
	if(keysym == XK_f)
		mlx->max_iter += 10 + (mlx->max_iter/10);
	if(keysym == XK_g)
		mlx->max_iter -= 10 + (mlx->max_iter/10);
	if(keysym == XK_Up || keysym == XK_w)
		mlx->y_offset -= 0.4 * mlx->zoom_level;
	if(keysym == XK_Down || keysym == XK_s)
		mlx->y_offset += 0.4 * mlx->zoom_level;
	if(keysym == XK_Left || keysym == XK_a)
		mlx->x_offset -= 0.4 * mlx->zoom_level;
	if(keysym == XK_Right || keysym == XK_d)
		mlx->x_offset += 0.4 * mlx->zoom_level;
	ft_render_frame(mlx);
	return (0);
}
