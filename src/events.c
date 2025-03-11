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

int ft_on_scroll(int keysym, int x, int y, t_data *mlx)
{
	(void)x;
	(void)y;
	ft_printf("Keyrelease: %d, x %d, y %d\n", keysym, x, y);
	if(keysym == 4)
		ft_printf("scroll up\n");
	if(keysym == 5)
		ft_printf("scroll down\n");
	ft_render_frame(mlx);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *mlx)
{    
	ft_printf("Keyrelease: %d\n", keysym);
	if(keysym == XK_Escape)
		ft_free_all(mlx);
	if(keysym == XK_Up || keysym == XK_w)
		ft_printf("UP\n");
	if(keysym == XK_Down || keysym == XK_s)
		ft_printf("DOWN\n");
	if(keysym == XK_Left || keysym == XK_a)
		ft_printf("LEFT\n");
	if(keysym == XK_Right || keysym == XK_d)
		ft_printf("RIGHT\n");
	ft_render_frame(mlx);
	return (0);
}
