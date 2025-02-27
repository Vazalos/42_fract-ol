/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:04:36 by david-fe          #+#    #+#             */
/*   Updated: 2025/01/08 12:04:39 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace_alt(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace_alt(str[i]) != 0)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
