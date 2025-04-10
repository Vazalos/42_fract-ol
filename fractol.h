/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:51:07 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/28 13:06:33 by david-fe         ###   ########.fr       */
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
# define SIN_LIMIT 100000
# define ZOOM 1.4
# define COLOR_SHIFT 20

# define BLACK	0xFF000000

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
	int			fractal_set;
	t_img		img;
	//iterations
	t_complex	z;
	t_complex	c;
	int			max_iter;
	int			escape_val;
	//window & zoom
	t_range		win_xrange;
	t_range		win_yrange;
	t_range		xr_range;
	t_range		yi_range;
	double		min_xr;
	double		max_xr;
	double		min_yi;
	double		max_yi;
	double		scale_x;
	double		scale_y;
	double		x_offset;
	double		y_offset;
	double		zoom;
	double		zoom_level;
	//colors
	double		j;
	double		k;
	double		l;
	int			color_profile;
	double		red_shift;
	double		green_shift;
	double		blue_shift;
	//julia
	t_complex	julia;
	t_complex	sin_julia;
	//function movement
	int			toggle_julia;
}	t_data;

//MAIN.C
int		ft_free_all(t_data *mlx);
void	ft_error(void);
void	ft_control_help(void);

//PARSE.C
int		ft_parse_name(int argc, char **argv);
void	ft_parse_fractal(t_data *mlx, char **argv);
void	ft_valid_julia_args(char **argv);

//INITS.C
int		ft_init_mlx(t_data *mlx);
void	ft_init_values(t_data *mlx);
t_range	ft_range(double min, double max);

//RENDER.C
void	ft_draw_image(t_data *mlx);
int		ft_render_frame(t_data *mlx);
void	ft_resume_render(t_data *mlx);

//FRACTAL.C
void	ft_mandelbrot(int x, int y, t_data *mlx);
void	ft_julia(int x, int y, t_data *mlx);
void	ft_sin(int x, int y, t_data *mlx);
void	ft_sin_julia(int x, int y, t_data *mlx);

//DRAW_UTILS.C
void	ft_put_pixel(t_data *mlx, int x, int y, int color);
void	ft_reset_view(t_data *mlx);
void	ft_cursor_offset(int x, int y, t_data *mlx, int zoomin);

//EVENTS.C
void	ft_event_handler(t_data *mlx);
int		ft_on_scroll(int keysym, int x, int y, t_data *mlx);
int		ft_on_keypress(int keysym, t_data *mlx);
int		ft_move_fractal(int x, int y, t_data *mlx);

//EVENT_HELPERS.C
void	ft_color_shift(int keysym, t_data *mlx);
void	ft_toggle_julia(t_data *mlx);
int		ft_shift_fractal(int x, int y, t_data *mlx);
void	ft_select_fractal(int keysym, t_data *mlx);

//COLOR_UTILS.C
int		ft_encode_argb(int a, int r, int g, int b);
int		ft_get_a(int argb);
int		ft_get_r(int argb);
int		ft_get_g(int argb);
int		ft_get_b(int argb);

//COLOR_PROFILES.C
int		ft_color_profile(int i, t_data *mlx);
int		ft_legacy_color(int i, t_data *mlx);
int		ft_2nd_color(int i, t_data *mlx);
int		ft_3rd_color(int i, t_data *mlx);
int		ft_4th_color(int i, t_data *mlx);

//MATH_UTILS.C
double	ft_map(double to_scale, t_range old_scale, t_range new_scale);
double	ft_squared(double n);
double	ft_cubed(double n);
double	ft_atod(char *str);

#endif
