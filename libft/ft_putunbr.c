/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:36:44 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/21 16:39:51 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digitucnt(unsigned int to_count)
{
	unsigned int	i;

	i = 0;
	if (to_count == 0)
		return (1);
	while (to_count > 0)
	{
		to_count = to_count / 10;
		i++;
	}
	return (i);
}

unsigned int	ft_putunbr(unsigned int nbr)
{
	unsigned int	count;

	count = ft_digitucnt(nbr);
	if (nbr > 9)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	else
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
	return (count);
}
/*
int	main(void)
{
	unsigned int	unum = -294967295;
	ft_printf("\n");
	ft_putunbr(unum);
	printf("\n%u\n", unum);
}*/
