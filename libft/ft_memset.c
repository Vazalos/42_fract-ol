/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:09 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/24 14:10:49 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	if (!ptr)
		return (NULL);*/

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*temptr;

	temptr = (unsigned char *)ptr;
	while (n > 0)
	{
		*temptr = (unsigned char) c;
		temptr++;
		n--;
	}
	return (ptr);
}
