/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:39:44 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/23 13:13:37 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*temptr;

	temptr = (unsigned char *)ptr;
	while (n > 0)
	{
		*temptr = '\0';
		temptr++;
		n--;
	}
}
