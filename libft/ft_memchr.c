/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:06:55 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/28 16:08:19 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temptr;
	unsigned char	tempc;

	i = 0;
	temptr = (unsigned char *)s;
	tempc = (unsigned char)c;
	while (i < n)
	{
		if (temptr[i] == tempc)
		{
			return ((void *)(temptr + i));
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{*/
/*	char	*ptr;
	int		c;
	size_t	n;

	if(argc != 4)
	{
		printf("wrong params");
		return(0);	
	}
	ptr = argv[1];
	c = atoi(argv[2]);
	n = (size_t)(atoi(argv[3]));

	printf("%p", ft_memchr(ptr, c, n));*/
	/*
	char	*str = "Search this phrase";

	printf("%p\n%p", &str[7], ft_memchr(str, 116, 99));
}*/
