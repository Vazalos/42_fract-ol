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
# include <stdlib.h>

typedef struct s_coord
{
	int x;
	int y;
} t_fractal;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

int	encode_argb(int a, int r, int g, int b);
int	get_t(int argb);
int	get_r(int argb);
int	get_g(int argb);
int	get_b(int argb);

#endif
