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

void	ft_event_handler(t_data *mlx)
{
	mlx_mouse_hook(mlx->window, ft_on_scroll, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_on_keypress, mlx);
	mlx_hook(mlx->window, DestroyNotify, 0, ft_free_all, mlx);
}

int ft_on_scroll(int keysym, int x, int y, t_data *mlx)
{
	(void)x;
	(void)y;
	if(keysym == 4)
	{
		mlx->fract_xrange.min *= 1.25;
		mlx->fract_xrange.max *= 1.25;
		mlx->fract_yrange.min *= 1.25;
		mlx->fract_yrange.max *= 1.25;
	}
	if(keysym == 5)
	{
		mlx->fract_xrange.min *= 0.8;
		mlx->fract_xrange.max *= 0.8;
		mlx->fract_yrange.min *= 0.8;
		mlx->fract_yrange.max *= 0.8;
	}
	ft_render_frame(mlx);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *mlx)
{   
	if(keysym == XK_Escape)
		ft_free_all(mlx);
	if(keysym == XK_Up || keysym == XK_w)
	{		
		mlx->fract_yrange.min += -0.2;
		mlx->fract_yrange.max += -0.2;
	}
	if(keysym == XK_Down || keysym == XK_s)
	{
		mlx->fract_yrange.min += 0.2;
		mlx->fract_yrange.max += 0.2;
	}
	if(keysym == XK_Left || keysym == XK_a)
	{
		mlx->fract_xrange.min += 0.2;
		mlx->fract_xrange.max += 0.2;
	}
	if(keysym == XK_Right || keysym == XK_d)
	{
		mlx->fract_xrange.min += -0.2;
		mlx->fract_xrange.max += -0.2;
	}
	ft_render_frame(mlx);
	return (0);
}
