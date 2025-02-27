/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:05:00 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/30 17:13:20 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			big = big + i;
			return ((char *)big);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str1[] = "-62,47 +62,47";
	char	str2[] = "47";
	size_t	n =  20;

	printf("%s", ft_strstr(str1, str2, n));
}*/
