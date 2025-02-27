/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:07 by david-fe          #+#    #+#             */
/*   Updated: 2024/08/19 18:05:45 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlen(const char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos])
		pos++;
	return (pos);
}
*/
unsigned int	ft_strlcat(const char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;
	char			*temp_d;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	temp_d = (char *)dst;
	if (size <= dlen)
		return (slen + size);
	else
	{
		while (src[i] != 0 && i < (size - dlen - 1))
		{
			temp_d[dlen + i] = src[i];
			i++;
		}
		temp_d[dlen + i] = '\0';
		return (slen + dlen);
	}
}
/*
int	main(void)
{
	char dest1[30] = "1337 42";
	char src2[] = "Born to code";
	unsigned int n;

	n = 30;
	printf("%u", ft_strlcat(dest1, src2, n));
	return(0);
}*/
