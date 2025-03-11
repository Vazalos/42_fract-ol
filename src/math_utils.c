/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:11:05 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/11 15:37:57 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_window_scale(double unscaled_num, double new_min,
				double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}
