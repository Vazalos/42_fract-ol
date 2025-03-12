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

double	ft_map(double to_scale, t_range old_scale, t_range new_scale)
{
	return ((new_scale.max - new_scale.min) * (to_scale - old_scale.min)
	/ (old_scale.max - old_scale.min) + new_scale.min);
}
/*
int	main(void)
{
	t_range old_scale;
	t_range new_scale;
	int	i;

	old_scale.min = 0;
	old_scale.max = 1000;
	new_scale.min = 2;
	new_scale.max = -2;
	i = (int)old_scale.min;

	while(i <= (int)old_scale.max) 
	{
		if(i % 10 == 0)
			printf("%d => %f\n", i, ft_map((double)i, old_scale, new_scale));
		i++;
	}
}*/
