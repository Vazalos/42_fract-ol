/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:14:16 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/23 17:15:17 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;
	size_t			i;

	if (dest == 0 && src == 0)
		return (dest);
	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	source[50] = "Abcdwxyz";
	char	destin[50] = "eeeeeeeeeeeeeeeeeeeu";
	size_t	len = 5;

	printf("before: %s\n", destin);
	ft_memcpy(destin, source, len);
	printf(" after: %s\n", destin);
}*/
