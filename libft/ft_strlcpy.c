/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:40:50 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/24 17:10:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	if (size >= ft_strlen(src) + 1)
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (size != 0)
	{
		while (size - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dst[30] = "";
	char    src[] = "this is sample text!";
	size_t	size = 10;

	printf("\nsrc: %s\ndst: %s\n- - - - - - - - - -\n", src, dst);
	ft_strlcpy(dst, src, size);
	printf("\nsrc: %s\ndst: %s", src, dst);

	//printf("empty string is now: %s", ft_strcpy(dest0, src0));
}*/
