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

typedef struct	s_data {
	void	*connect;
	void	*window;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_line_len;
	int		img_endian;
} t_data;

int	encode_argb(int a, int r, int g, int b);
int	get_a(int argb);
int	get_r(int argb);
int	get_g(int argb);
int	get_b(int argb);

#endif
