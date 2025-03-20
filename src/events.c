/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:51 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/11 10:29:29 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>

void	ft_event_handler(t_data *mlx)
{
	mlx_mouse_hook(mlx->window, ft_on_scroll, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_on_keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, 0, ft_free_all, mlx);
}
/*
void	ft_cursor_offset(int x, int y, t_data *mlx)
{
	double	xr_zoom_diff;
	double	yi_zoom_diff;
	double	x_percent;
	double	y_percent; 

	x_percent = (double)x / (double)WIDTH;
	xr_zoom_diff = ((fabs(mlx->min_xr)+fabs(mlx->max_xr)) - (WIDTH/(mlx->scale*mlx->zoom)));
	mlx->min_xr -= xr_zoom_diff * x_percent;
	mlx->max_xr += xr_zoom_diff * (1 - x_percent);
	y_percent = (double)y / (double)HEIGHT;
	yi_zoom_diff = ((fabs(mlx->min_yi)+fabs(mlx->max_yi)) - (WIDTH/(mlx->scale*mlx->zoom)));
	mlx->min_yi -= xr_zoom_diff * y_percent;
	mlx->max_yi += xr_zoom_diff * (1 - y_percent);
}*/

int ft_on_scroll(int button, int x, int y, t_data *mlx)
{
	mlx->x_100 = (double)x / (double)WIDTH;
	mlx->y_100 = (double)y / (double)HEIGHT;
	if(button == 4)
	{
		mlx->zoom /= 1.1;
		//ft_cursor_offset(x, y, mlx);
	}
	if(button == 5)
	{
		mlx->zoom *= 1.1;
		//ft_cursor_offset(x, y, mlx);
	}
	ft_render_frame(mlx);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *mlx)
{   
	if(keysym == XK_Escape)
		ft_free_all(mlx);
	if(keysym == XK_f)
		mlx->max_iter += 5;
	if(keysym == XK_g)
		mlx->max_iter -= 5;
	if(keysym == XK_Up || keysym == XK_w)
		mlx->y_offset += -0.2;
	if(keysym == XK_Down || keysym == XK_s)
		mlx->y_offset += 0.2;
	if(keysym == XK_Left || keysym == XK_a)
		mlx->x_offset += -0.2;
	if(keysym == XK_Right || keysym == XK_d)
		mlx->x_offset += 0.2;
	ft_render_frame(mlx);
	return (0);
}
