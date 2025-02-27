/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:36:48 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/30 16:21:39 by david-fe         ###   ########.fr       */
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
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*new_str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
