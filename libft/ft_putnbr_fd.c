/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:43:42 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/30 16:45:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digitcnt(int to_count)
{
	unsigned int	i;

	i = 0;
	if (to_count == 0)
		return (1);
	if (to_count == -2147483648)
		return (11);
	if (to_count < 0)
		to_count = -to_count;
	while (to_count > 0)
	{
		to_count = to_count / 10;
		i++;
	}
	return (i);
}

unsigned int	ft_putnbr_fd(int nbr, int fd)
{
	unsigned int	count;

	count = ft_digitcnt(nbr);
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			write(fd, "-", 1);
			nbr = -nbr;
			count++;
		}
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
		else
		{
			nbr = nbr + '0';
			write(fd, &nbr, 1);
		}
	}
	return (count);
}
/*
int	main(void)
{
	ft_putnbr_fd(2147483647);
}*/
