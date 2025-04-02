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
/* ************************************************************************** */\

#include "../fractol.h"
#include <math.h>
#include <stdio.h>

int	ft_shift_fractal(int x, int y, t_data *mlx);
int	ft_shift_fractal2(int x, int y, t_data *mlx);

void	ft_event_handler(t_data *mlx)
{
	mlx_mouse_hook(mlx->window, ft_on_scroll, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_on_keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, 0, ft_free_all, mlx);
	mlx_hook(mlx->window, 6, 1L<<6, ft_shift_fractal2, mlx);
}


int	ft_shift_fractal2(int x, int y, t_data *mlx)
{
	static int i;

	i++;
	if (i == mlx->max_iter/(5*(mlx->max_iter/10)))
	{
		i = 0;
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
		ft_resume_render(mlx);
	}
	return(0);
}

int	ft_shift_fractal(int x, int y, t_data *mlx)
{
	if (mlx->fractal_set == 1)
	{
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
		mlx->fractal_set = 2;
	}
	if (mlx->fractal_set == 2)
	{
		mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
		mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
	}
	return(0);
}

int ft_on_scroll(int button, int x, int y, t_data *mlx)
{
	if(button == 1)
	{
		mlx->zoom *= 50;
		ft_cursor_offset(x, y, mlx, 1);
		mlx->zoom /= 50;
	}
	if(button == 2)
	{
		ft_printf("%i, %i\n", x, y);
		ft_shift_fractal(x, y, mlx);
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

void	ft_fractal_select(int keysym, t_data *mlx)
{
	if(keysym == XK_m)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 1;
		ft_reset_view(mlx);
	}
	if(keysym == XK_j)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 2;
		ft_reset_view(mlx);
	}
	if(keysym == XK_n)
	{
		mlx->max_iter = MAX_ITER;
		mlx->fractal_set = 3;
		ft_reset_view(mlx);
	}
}

void	ft_color_shift(int keysym, t_data *mlx)
{
	if(keysym == XK_q)
	{
		mlx->red_shift = 0;
		mlx->green_shift = 0;
		mlx->blue_shift = 0;
	}
	if(keysym == XK_1)
		mlx->red_shift -= COLOR_SHIFT;
	if(keysym == XK_2)
		mlx->red_shift += COLOR_SHIFT;
	if(keysym == XK_3)
		mlx->green_shift -= COLOR_SHIFT;
	if(keysym == XK_4)
		mlx->green_shift += COLOR_SHIFT;
	if(keysym == XK_5)
		mlx->blue_shift -= COLOR_SHIFT;
	if(keysym == XK_6)
		mlx->blue_shift += COLOR_SHIFT;
}

int	ft_on_keypress(int keysym, t_data *mlx)
{   
	if(keysym == XK_Escape)
		ft_free_all(mlx);
	if(keysym == XK_r)
		ft_reset_view(mlx);
	if(keysym == XK_1 || keysym == XK_2 || keysym == XK_3 || keysym == XK_4
		|| keysym == XK_5 || keysym == XK_6 || keysym == XK_q)
		ft_color_shift(keysym, mlx);
	if(keysym == XK_j || keysym == XK_n || keysym == XK_m)
		ft_fractal_select(keysym, mlx);
	if(keysym == XK_e )
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
