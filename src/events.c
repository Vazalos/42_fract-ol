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
#include <stdio.h>

void	ft_event_handler(t_data *mlx)
{
	mlx_mouse_hook(mlx->window, ft_on_scroll, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_on_keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, 0, ft_free_all, mlx);
}

void	ft_visual_range(t_data *mlx)
{
	mlx->xr_range.min = mlx->min_xr + mlx->x_offset;
	mlx->xr_range.max = mlx->max_xr + mlx->x_offset;
	mlx->yi_range.min = mlx->min_yi + mlx->y_offset;
	mlx->yi_range.max = mlx->max_yi + mlx->y_offset;
	//printf("min X:%f max X:%f min Y:%f max Y:%f \n", mlx->min_xr, mlx->max_xr, mlx->min_yi, mlx->max_yi);
	//printf("xoff %f | yoff %f\n", mlx->x_offset, mlx->y_offset);
}

void	ft_cursor_offset(int x, int y, t_data *mlx, int zoomin)
{
	double	cursor_xr;
	double	cursor_yi;

	cursor_xr = mlx->min_xr + (x * (mlx->scale_x));
	cursor_yi = mlx->max_yi - ((WIDTH - y) * (mlx->scale_y));
	//printf("xPOS %f yPOS %f\n", cursor_xr, cursor_yi);
	if (zoomin == 0)
	{
		mlx->min_xr = cursor_xr + (mlx->min_xr - cursor_xr) * mlx->zoom;
		mlx->max_xr = cursor_xr + (mlx->max_xr - cursor_xr) * mlx->zoom;
		mlx->min_yi = cursor_yi + (mlx->min_yi - cursor_yi) * mlx->zoom;
		mlx->max_yi = cursor_yi + (mlx->max_yi - cursor_yi) * mlx->zoom;
		mlx->zoom_level *= mlx->zoom; 
	}
	if (zoomin == 1)
	{
		mlx->min_xr = cursor_xr + (mlx->min_xr - cursor_xr) / mlx->zoom;
		mlx->max_xr = cursor_xr + (mlx->max_xr - cursor_xr) / mlx->zoom;
		mlx->min_yi = cursor_yi + (mlx->min_yi - cursor_yi) / mlx->zoom;
		mlx->max_yi = cursor_yi + (mlx->max_yi - cursor_yi) / mlx->zoom;
		mlx->zoom_level /= mlx->zoom; 
	}
		mlx->scale_x = (mlx->max_xr - mlx->min_xr)/(WIDTH - 1);
		mlx->scale_y = (mlx->max_yi - mlx->min_yi)/(HEIGHT - 1);
}

int ft_on_scroll(int button, int x, int y, t_data *mlx)
{
	if(button == 1)
	{
		ft_cursor_offset(x, y, mlx, 2);
	}
	if(button == 4)
	{
		ft_cursor_offset(x, y, mlx, 1);
	}
	if(button == 5)
	{
		ft_cursor_offset(x, y, mlx, 0);
	}
	ft_render_frame(mlx);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *mlx)
{   
	if(keysym == XK_Escape)
		ft_free_all(mlx);
	if(keysym == XK_r)
	{
		mlx->y_offset = 0;
		mlx->x_offset = 0;
		mlx->zoom = ZOOM;
		mlx->zoom_level = mlx->zoom;
		mlx->min_xr = -2.0;
		mlx->max_xr = 2.0;
		mlx->min_yi = -2.0;
		mlx->max_yi = 2.0;
	}
	if(keysym == XK_f)
		mlx->max_iter += 2;
	if(keysym == XK_g)
		mlx->max_iter -= 2;
	if(keysym == XK_Up || keysym == XK_w)
		mlx->y_offset -= 0.2 * mlx->zoom_level;
	if(keysym == XK_Down || keysym == XK_s)
		mlx->y_offset += 0.2 * mlx->zoom_level;
	if(keysym == XK_Left || keysym == XK_a)
		mlx->x_offset -= 0.2 * mlx->zoom_level;
	if(keysym == XK_Right || keysym == XK_d)
		mlx->x_offset += 0.2 * mlx->zoom_level;
	ft_render_frame(mlx);
	return (0);
}
