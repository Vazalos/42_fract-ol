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

# define WIDTH	1000
# define HEIGHT	1000
# define MLX_ERROR 1
# define MAX_ITER 42
# define ZOOM 1.4


//COLOR defines
# define BLACK	0xFF000000
# define WHITE	0xFFFFFFFF
# define RED	0xFFFF0000
# define GREEN	0xFF00FF00
# define BLUE	0xFF0000FF

typedef struct s_range
{
	double	max;
	double	min;
}	t_range;

typedef struct s_complex
{
	double	xr;
	double	yi;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	//mlx
	void		*connect;
	void		*window;
	char		*fractal_name;
	t_img		img;
	//iterations
	t_complex	z;
	t_complex	c;
	int			max_iter;
	int			escape_val;
	//resolution
	double		center;
	double		scale_x;
	double		scale_y;
	t_range		win_xrange;
	t_range		win_yrange;
	t_range		xr_range;
	t_range		yi_range;
	double		min_xr;
	double		max_xr;
	double		min_yi;
	double		max_yi;
	double		mid_xr;
	double		mid_yi;	
	double		x_offset;
	double		y_offset;
	double		zoom;
	double		zoom_level;
	double		x_dist;
	double		y_dist;
	double		x_ratio;
	double		y_ratio;
	//colors
	t_range		color_range;
	t_range		color_iter;
	int			color_profile;
}	t_data;

//MAIN.C
int		ft_free_all(t_data *mlx);

//COLOR_UTILS.C
int		ft_encode_argb(int a, int r, int g, int b);
int		ft_get_a(int argb);
int		ft_get_r(int argb);
int		ft_get_g(int argb);
int		ft_get_b(int argb);

//COLOR_PROFILES.C
int		ft_color_profile (int i, t_data *mlx);
int		ft_legacy_color (int i, t_data *mlx);
int		ft_2nd_color (int i, t_data *mlx);
int		ft_3rd_color (int i, t_data *mlx);
int		ft_4th_color (int i, t_data *mlx);


//DRAW_UTILS.C
void	ft_put_pixel(t_data *mlx, int x, int y, int color);
int		ft_draw_texture(t_data *mlx);
int		ft_render_frame(t_data *mlx);

//EVENTS.C
void	ft_event_handler(t_data *mlx);
int		ft_on_scroll(int keysym, int x, int y, t_data *mlx);
int		ft_on_keypress(int keysym, t_data *mlx);

//FRACTAL.C
void	ft_visual_range(t_data *mlx);
void	ft_mandelbrot(int x, int y, t_data *mlx);

//MATH_UTILS.C
double	ft_map(double to_scale, t_range old_scale, t_range new_scale);
t_range	ft_range(double min, double max);
double	ft_squared(double n);

//INITS.C
int		ft_init_mlx(t_data *mlx, char *name);
void	ft_init_values(t_data *mlx);

#endif
