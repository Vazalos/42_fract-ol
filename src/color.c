/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:38:56 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/04 16:39:23 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	encode_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	get_t(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_r(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_g(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_b(int argb)
{
	return (argb & 0xFF);
}

