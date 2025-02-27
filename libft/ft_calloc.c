/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:32:09 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/28 16:57:07 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (total > 2147483647)
		return (0);
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*
int	main(void)
{
	unsigned char	*ptr;

	ptr = ft_calloc(5, 1);
	free(ptr);
}*/
