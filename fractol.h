/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:51:07 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/27 14:52:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MLX_ERROR 1

typedef struct s_complex_num
{
	//real axis
	int		x;
	//imaginary axis
	int		y;
}	t_complex_num;

typedef struct s_data
{
	void	*connect;
	void	*window;
	char	*fractal_name;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_line_len;
	int		img_endian;
}	t_data;

//MAIN.C
int		ft_free_all(t_data *mlx);

//COLOR.C
int		ft_encode_argb(int a, int r, int g, int b);
int		ft_get_a(int argb);
int		ft_get_r(int argb);
int		ft_get_g(int argb);
int		ft_get_b(int argb);

//DRAW_UTILS.C
void	ft_mlx_put_pixel(t_data *mlx, int x, int y, int color);
int		ft_draw_texture(t_data *mlx);
int		ft_render_frame(t_data *mlx);

//EVENTS.C
int		ft_on_scroll(int keysym, int x, int y, t_data *mlx);
int		ft_on_keypress(int keysym, t_data *mlx);

//FRACTAL.C
void	ft_render_fractal(int x, int y, t_data *mlx, char **argv);

//MATH_UTILS.C
double	ft_window_scale(double unscaled_num, double new_min,
			double new_max, double old_max);

#endif
