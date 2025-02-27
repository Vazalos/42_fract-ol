/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:47:54 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/29 13:00:24 by david-fe         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*new_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new_str[i + len1] = s2[i];
		i++;
	}
	new_str[i + len1] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char	*s1 = "Add water";
	char	*s2 = " to the mix";
	char	*s_new;

	s_new = ft_strjoin(s1, s2);
	printf("%s", s_new);
}*/
