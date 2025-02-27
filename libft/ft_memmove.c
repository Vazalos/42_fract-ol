/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:17:17 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/24 14:19:15 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;
	size_t			i;

	i = 0;
	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (tempdest > tempsrc)
		while (i++ < n)
			tempdest[n - i] = tempsrc[n - i];
	else
		while (i++ < n)
			tempdest[i - 1] = tempsrc[i - 1];
	return (dest);
}
/*
int	main(void)
{
	char	source[50] = "Abcdefghijklmnopqrstuvwxyz";
	size_t	len = 5;

	printf("before: %s\n", source);
	ft_memmove(source + 4, source, len);
	printf(" after: %s\n", source);
}*/
