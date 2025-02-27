/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:26:10 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/29 14:27:05 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	init;
	size_t	fin;

	init = 0;
	fin = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[init]) && s1[init])
		++init;
	while (ft_strchr(set, s1[fin]) && s1[init])
		--fin;
	return (ft_substr(s1, init, ((fin - init) + 1)));
}
/*
int	main(void)
{
	char	*str = "lorem \n ipsum \t dolor \n sit \t amet";
	char	*limit = " ";
	char	*trimmed;

	trimmed = ft_strtrim(str, limit);
	printf("%s", trimmed);
	free(trimmed);
}*/
