/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:30:27 by david-fe          #+#    #+#             */
/*   Updated: 2024/08/18 20:00:22 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char*s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char		str1[] = "test\200";
	char		str2[] = "test\0";
	unsigned int	n = 6;

	printf("%s\n &\n%s\ndiff of: %d",
		str1, str2, ft_strncmp(str1, str2, n));
	//ft_strncmp(str1, str2, 5);
}*/
