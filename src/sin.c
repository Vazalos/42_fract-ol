/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:44:27 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/07 16:05:25 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex sin_complex(t_complex z) {
    t_complex result;
    result.xr = sin(z.xr) * cosh(z.yi);
    result.yi = cos(z.xr) * sinh(z.yi);
    return result;
}

t_complex multiply(t_complex a, t_complex b) {
    t_complex result;
    result.xr = a.xr * b.xr - a.yi * b.yi;
    result.yi = a.xr * b.yi + a.yi * b.xr;
    return result;
}

t_complex add(t_complex a, t_complex b) {
    t_complex result;
    result.xr = a.xr + b.xr;
    result.yi = a.yi + b.yi;
    return result;
}

t_complex sin_squared_plus_c(t_complex z, t_complex c) {
    // Calculate sin(z)
    t_complex sin_z;
	t_complex sin_z_squared;
	t_complex result;

	sin_z.xr = sin(z.xr) * cosh(z.yi);
	sin_z.yi = cos(z.xr) * sinh(z.yi);
	sin_z_squared.xr = ft_squared(sin_z.xr) - ft_squared(sin_z.yi);
	sin_z_squared.yi = (sin_z.xr * sin_z.yi) + (sin_z.xr * sin_z.yi);
	result.xr = sin_z_squared.xr + c.xr;
	result.yi = sin_z_squared.yi + c.yi;
    
    return result;
}
