/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:36:36 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/30 16:38:01 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr_fd("(null)", fd));
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
