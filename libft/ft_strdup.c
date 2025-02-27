/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:07:28 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/13 13:07:31 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptrdup;
	size_t	slen;
	size_t	i;

	slen = ft_strlen((char *)src);
	ptrdup = malloc((slen + 1) * sizeof(char));
	if (!ptrdup)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		ptrdup[i] = src[i];
		i++;
	}
	ptrdup[i] = '\0';
	return (ptrdup);
}
