/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:11:05 by david-fe          #+#    #+#             */
/*   Updated: 2025/03/28 13:01:02 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_map(double to_scale, t_range old_scale, t_range new_scale)
{
	return ((new_scale.max - new_scale.min) * (to_scale - old_scale.min)
		/ (old_scale.max - old_scale.min) + new_scale.min);
}

double	ft_squared(double n)
{
	return (n * n);
}

double	ft_cubed(double n)
{
	return (n * n * n);
}

static int	ft_spacenum(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

double	ft_atod(char *str)
{
	double	whole;
	double	decimal;
	double	div;
	int		sign;
	int		i;

	whole = 0.0;
	decimal = 0.0;
	div = 1.0;
	sign = 1;
	i = ft_spacenum(str);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		whole = (whole * 10.0) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal = (decimal * 10.0) + (str[i++] - '0');
		div *= 10;
	}
	decimal /= div;
	return (sign * (whole + decimal));
}
