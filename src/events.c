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

void	ft_visual_range(t_data *mlx)
{
	mlx->xr_range.min = mlx->min_xr + mlx->x_offset;
	mlx->xr_range.max = mlx->max_xr + mlx->x_offset;
	mlx->yi_range.min = mlx->min_yi + mlx->y_offset;
	mlx->yi_range.max = mlx->max_yi + mlx->y_offset;
}
/*
void	ft_cursor_offset(int x, int y, t_data *mlx)
{
	double	xr_zoom_diff;
	double	yi_zoom_diff;
	double	new_xdist;
	double	new_ydist;

	//printf("X vals %f %f %f\n", mlx->min_xr, mlx->mid_xr, mlx->max_xr);
	//printf("Y vals %f %f %f\n", mlx->min_yi, mlx->mid_yi, mlx->max_yi);	
	mlx->mid_xr = (mlx->x_dist/2)+mlx->min_xr;
	mlx->mid_yi = (mlx->y_dist/2)+mlx->min_yi;
	printf("X vals %f %f %f\n", mlx->min_xr, mlx->mid_xr, mlx->max_xr);
	printf("Y vals %f %f %f\n", mlx->min_yi, mlx->mid_yi, mlx->max_yi);
	mlx->x_dist = (fabs(mlx->min_xr)+fabs(mlx->max_xr));
	mlx->y_dist = (fabs(mlx->min_yi)+fabs(mlx->max_yi));
	printf("xdist %f ydist %f | ", mlx->x_dist, mlx->y_dist);
	mlx->mid_xr = (mlx->x_dist/2)+mlx->min_xr;
	mlx->mid_yi = (mlx->y_dist/2)+mlx->min_yi;
	printf("mid x %f mid y %f | ", mlx->mid_yi, mlx->mid_yi);
	new_xdist = mlx->x_dist * mlx->zoom;
	new_ydist = mlx->y_dist * mlx->zoom;
	printf("nxdst %f nydst %f |\n", new_xdist, new_ydist);
	mlx->x_ratio = (double)x / (double)WIDTH;
	mlx->y_ratio = (double)y / (double)HEIGHT;
	xr_zoom_diff = mlx->x_dist - new_xdist;
	yi_zoom_diff = mlx->y_dist - new_ydist;
	mlx->min_xr = mlx->mid_xr - (mlx->x_dist/2) - (xr_zoom_diff*mlx->x_ratio);
	mlx->max_xr = mlx->mid_xr + (mlx->x_dist/2) + (xr_zoom_diff*(1 - mlx->x_ratio));
	mlx->min_yi = mlx->mid_yi + (mlx->y_dist/2) + (yi_zoom_diff*(1 - mlx->y_ratio));
	mlx->max_yi = mlx->mid_yi - (mlx->y_dist/2) - (yi_zoom_diff*mlx->y_ratio);
	//printf("zoom %f | diff %f | mx:%f MX:%f | my:%f MY:%f\n", mlx->zoom, xr_zoom_diff, mlx->min_xr, mlx->max_xr, mlx->min_yi, mlx->max_yi); // PRINT VALUES AND FIND OUT WHAT'S WRONG
}*/

int ft_on_scroll(int button, int x, int y, t_data *mlx)
{
//	mlx->x_100 = (double)x / (double)WIDTH;
//	mlx->y_100 = (double)y / (double)HEIGHT;
	if(button == 4)
	{
		mlx->x_offset += (ft_map(x, mlx->win_xrange, mlx->xr_range) * 0.13 * fabs(mlx->zoom));
		mlx->y_offset += (ft_map(y, mlx->win_yrange, mlx->yi_range) * 0.13 * fabs(mlx->zoom));
		mlx->zoom /= fabs(1.25);
	}
	if(button == 5)
	{
		mlx->x_offset -= (ft_map(x, mlx->win_xrange, mlx->xr_range) * 0.13 * fabs(mlx->zoom));
		mlx->y_offset -= (ft_map(y, mlx->win_yrange, mlx->yi_range) * 0.13 * fabs(mlx->zoom));
		mlx->zoom *= fabs(1.25);
	}
	//ft_cursor_offset(x, y, mlx);
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
		mlx->zoom = 1;
		mlx->min_xr = -2.0;
		mlx->max_xr = 2.0;
		mlx->min_yi = -2.0;
		mlx->max_yi = 2.0;
	}
	if(keysym == XK_f)
		mlx->max_iter += 5;
	if(keysym == XK_g)
		mlx->max_iter -= 5;
	if(keysym == XK_Up || keysym == XK_w)
		mlx->y_offset += -0.2 * mlx->zoom;
	if(keysym == XK_Down || keysym == XK_s)
		mlx->y_offset += 0.2 * mlx->zoom;
	if(keysym == XK_Left || keysym == XK_a)
		mlx->x_offset += -0.2 * mlx->zoom;
	if(keysym == XK_Right || keysym == XK_d)
		mlx->x_offset += 0.2 * mlx->zoom;
	ft_render_frame(mlx);
	return (0);
}
