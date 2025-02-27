/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:09:15 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/28 16:24:24 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*temp1;
	unsigned char		*temp2;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[] = "argument1";
	char str2[] = "argument4";
	size_t	n = 20;

	printf("diff between two\n'%s'\n'%s'\nis: %d"
	, str1, str2, ft_memcmp(str1, str2, n));
}*/
