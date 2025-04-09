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

void	ft_event_handler(t_data *mlx)
{
	mlx_mouse_hook(mlx->window, ft_on_scroll, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_on_keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, 0, ft_free_all, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, ft_move_fractal, mlx);
}

int	ft_move_fractal(int x, int y, t_data *mlx)
{
	static int	i;

	if (mlx->toggle_julia == 1
		&& (mlx->fractal_set == 2 || mlx->fractal_set == 4))
	{
		i++;
		if (mlx->fractal_set == 2
			&& i == mlx->max_iter / (5 * (mlx->max_iter / 10)))
		{
			i = 0;
			mlx->julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
			mlx->julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
			ft_resume_render(mlx);
		}
		if (mlx->fractal_set == 4 && i == 20)
		{
			i = 0;
			mlx->sin_julia.xr = ft_map(x, mlx->win_xrange, mlx->xr_range);
			mlx->sin_julia.yi = ft_map(y, mlx->win_yrange, mlx->yi_range);
			ft_resume_render(mlx);
		}
		return (1);
	}
	return (0);
}

int	ft_on_scroll(int button, int x, int y, t_data *mlx)
{
	if (button == 1)
	{
		mlx->zoom *= 50;
		ft_cursor_offset(x, y, mlx, 1);
		mlx->zoom /= 50;
	}
	if (button == 2)
		ft_shift_fractal(x, y, mlx);
	if (button == 3)
	{
		mlx->zoom *= 25;
		ft_cursor_offset(x, y, mlx, 0);
		mlx->zoom /= 25;
	}
	if (button == 4)
		ft_cursor_offset(x, y, mlx, 1);
	if (button == 5)
		ft_cursor_offset(x, y, mlx, 0);
	ft_render_frame(mlx);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *mlx)
{
	if (keysym == XK_Escape)
		ft_free_all(mlx);
	if (keysym == XK_r)
		ft_reset_view(mlx);
	if (keysym == XK_t)
		ft_toggle_julia(mlx);
	if (keysym == XK_1 || keysym == XK_2 || keysym == XK_3 || keysym == XK_4
		|| keysym == XK_5 || keysym == XK_6 || keysym == XK_q || keysym == XK_e)
		ft_color_shift(keysym, mlx);
	if (keysym == XK_j || keysym == XK_n || keysym == XK_m || keysym == XK_h)
		ft_select_fractal(keysym, mlx);
	if (keysym == XK_f)
		mlx->max_iter += 10 + (mlx->max_iter / 10);
	if (keysym == XK_g)
		mlx->max_iter -= 10 + (mlx->max_iter / 10);
	if (keysym == XK_Up || keysym == XK_w)
		mlx->y_offset -= 0.4 * mlx->zoom_level;
	if (keysym == XK_Down || keysym == XK_s)
		mlx->y_offset += 0.4 * mlx->zoom_level;
	if (keysym == XK_Left || keysym == XK_a)
		mlx->x_offset -= 0.4 * mlx->zoom_level;
	if (keysym == XK_Right || keysym == XK_d)
		mlx->x_offset += 0.4 * mlx->zoom_level;
	ft_render_frame(mlx);
	return (0);
}
